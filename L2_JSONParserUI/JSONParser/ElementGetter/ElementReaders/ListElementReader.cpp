#include "ListElementReader.h"


ListElementReader::ListElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator) : _tokenGetter(tokenGetter), _mediator(mediator)
{

}

void ListElementReader::checkValue(size_t& state, std::shared_ptr<BaseToken> token, std::shared_ptr<JSONList> list)
{
    if (token->getType() == TOKEN::ARRAY_CLOSE && list->empty())
        state = ReaderStates::FINISHED;
    else if (token->getType() == TOKEN::CURLY_CLOSE || token->getType() == TOKEN::COMMA || token->getType() == TOKEN::COLON)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected " + token->toString());
    else if (token->getType() == TOKEN::ARRAY_CLOSE)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected end of array");
    else {
        list->push_back(this->_mediator->call(token));
        state = ReaderStates::READ_DELIMER;
    }
}

void ListElementReader::checkDelimer(size_t& state, std::shared_ptr<BaseToken> token)
{
    if (token->getType() == TOKEN::ARRAY_CLOSE)
        state = ReaderStates::FINISHED;
    else if (token->getType() == TOKEN::COMMA)
        state = ReaderStates::READ_VALUE;
    else if (token->getType() == TOKEN::COLON || TOKEN::CURLY_CLOSE)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected " + token->toString() + ". Maybe you forgot \",\" or \"]\"?");
    else if (token->getType() == TOKEN::ARRAY_OPEN || token->getType() == TOKEN::CURLY_OPEN ||
             token->getType() == TOKEN::NULL_TYPE || token->getType() == TOKEN::BOOLEAN ||
             token->getType() == TOKEN::STRING || token->getType() == TOKEN::NUMBER)
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unexpected valuable token. Maybe you forgot \",\" or \"]\"?");
}

std::shared_ptr<BaseElement> ListElementReader::readElement(std::shared_ptr<BaseToken> tokenTrigger)
{
    std::shared_ptr<BaseElement> element = std::make_shared<ListElement>(ListElement());
    std::shared_ptr<ElementValue> value = std::make_shared<ElementValue>();
    std::shared_ptr<JSONList> list = std::make_shared<JSONList>(JSONList());
    size_t state = ReaderStates::READ_VALUE;

    while (state != ReaderStates::FINISHED) {
        std::shared_ptr<BaseToken> token = this->_tokenGetter->getToken();

        if (state == ReaderStates::READ_VALUE)
            this->checkValue(state, token, list);
        else if (state == ReaderStates::READ_DELIMER)
            this->checkDelimer(state, token);
    }

    value->type = elementValueType::VECTOR;
    value->list = list;

    element->setValue(value);
    return element;
}

ListElementReader::~ListElementReader()
{

}
