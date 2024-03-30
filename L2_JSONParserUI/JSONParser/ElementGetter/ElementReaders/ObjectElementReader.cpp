#include "ObjectElementReader.h"


ObjectElementReader::ObjectElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator) : _tokenGetter(tokenGetter), _mediator(mediator)
{

}

std::string ObjectElementReader::checkKey(size_t& state, std::shared_ptr<BaseToken> token, std::shared_ptr<JSONObject> object)
{
    if (token->getType() == TOKEN::CURLY_CLOSE && object->empty()) {
        state = ReaderStates::FINISHED;
        return "";
    }
    else if (token->getType() == TOKEN::NUMBER || token->getType() == TOKEN::NULL_TYPE ||
             token->getType() == TOKEN::BOOLEAN || token->getType() == TOKEN::CURLY_OPEN ||
             token->getType() == TOKEN::ARRAY_OPEN)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected valuable token. Maybe you forgot to set a \"key\" or "
                             "wanted to close object with \"}\" instead?");
    else if (token->getType() == TOKEN::ARRAY_CLOSE || token->getType() == TOKEN::COMMA ||
             token->getType() == TOKEN::COLON)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected " + token->toString() + ". Maybe you forgot to set a \"key\" or "
                                                                 "wanted to close object with \"}\" instead?");
    else if (token->getType() == TOKEN::CURLY_CLOSE)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected end of object. Maybe you forgot to set \"key\": value pair "
                             "or last comma was redundant?");
    else {
        state = ReaderStates::READ_COLON;
        return token->getValue();
    }
}

void ObjectElementReader::checkColon(size_t& state, std::shared_ptr<BaseToken> token)
{
    if (token->getType() == TOKEN::STRING || token->getType() == TOKEN::NULL_TYPE ||
        token->getType() == TOKEN::BOOLEAN || token->getType() == TOKEN::CURLY_OPEN ||
        token->getType() == TOKEN::ARRAY_OPEN || token->getType() == TOKEN::NUMBER)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected valuable token. Maybe you forgot \":\" before it?");
    else if (token->getType() == TOKEN::ARRAY_CLOSE || token->getType() == TOKEN::COMMA)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Extraneous " + token->toString() + ". Maybe you forgot \":\" before it?");
    else if (token->getType() == TOKEN::CURLY_CLOSE)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected end of object. Expected \":\".");
    else
        state = ReaderStates::READ_VALUE;
}

std::shared_ptr<BaseElement> ObjectElementReader::checkValue(size_t& state, std::shared_ptr<BaseToken> token)
{
    if (token->getType() == TOKEN::COLON || token->getType() == TOKEN::COMMA ||
        token->getType() == TOKEN::ARRAY_CLOSE)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Extraneous " + token->toString() + ". Did you wanted to set a value after \":\"?");
    else if (token->getType() == TOKEN::CURLY_CLOSE)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected end of object. Maybe you forget to set value after \":\"?");
    else {
        state = ReaderStates::READ_DELIMER;
        return this->_mediator->call(token);
    }
}

void ObjectElementReader::checkDelimer(size_t& state, std::shared_ptr<BaseToken> token)
{
    if (token->getType() == TOKEN::CURLY_CLOSE)
        state = ReaderStates::FINISHED;
    else if (token->getType() == TOKEN::COMMA)
        state = ReaderStates::READ_KEY;
    else if (token->getType() == TOKEN::COLON || token->getType() == TOKEN::ARRAY_CLOSE)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected " + token->toString() + ". Expected \",\" or \"}\" instead.");
    else if (token->getType() == TOKEN::ARRAY_OPEN || token->getType() == TOKEN::CURLY_OPEN ||
             token->getType() == TOKEN::NULL_TYPE || token->getType() == TOKEN::BOOLEAN ||
             token->getType() == TOKEN::STRING || token->getType() == TOKEN::NUMBER)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected valuable token. Expected \",\" or \"}\" instead.");
}

std::shared_ptr<BaseElement> ObjectElementReader::readElement(std::shared_ptr<BaseToken> tokenTrigger)
{
    std::shared_ptr<BaseElement> element = std::make_shared<ObjectElement>(ObjectElement());
    std::shared_ptr<ElementValue> value = std::make_shared<ElementValue>();
    std::shared_ptr<JSONObject> object = std::make_shared<JSONObject>(JSONObject());
    size_t state = ReaderStates::READ_KEY;

    while (state != ReaderStates::FINISHED) {
        std::shared_ptr<BaseToken> token = this->_tokenGetter->getToken();
        std::string key;
        std::shared_ptr<BaseElement> value;

        if (state == ReaderStates::READ_KEY)
            key = checkKey(state, token, object);
        else if (state == ReaderStates::READ_COLON)
            checkColon(state, token);
        else if (state == ReaderStates::READ_VALUE)
            value = checkValue(state, token);
        else if (state == ReaderStates::READ_DELIMER)
            checkDelimer(state, token);

        object->insert({key, value});
    }

    value->type = elementValueType::MAP;
    value->object = object;

    element->setValue(value);
    return element;
}

ObjectElementReader::~ObjectElementReader()
{

}
