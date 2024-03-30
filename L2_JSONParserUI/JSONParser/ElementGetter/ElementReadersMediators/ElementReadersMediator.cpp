 #include "ElementReadersMediator.h"


ElementReadersMediator::ElementReadersMediator()
{

}

void ElementReadersMediator::setBooleanElementReader(std::shared_ptr<BooleanElementReader> booleanElementReader)
{
    this->booleanElementReader = booleanElementReader;
}

void ElementReadersMediator::setListElementReader(std::shared_ptr<ListElementReader> listElementReader)
{
    this->listElementReader = listElementReader;
}

void ElementReadersMediator::setNullElementReader(std::shared_ptr<NullElementReader> nullElementReader)
{
    this->nullElementReader = nullElementReader;
}

void ElementReadersMediator::setNumberElementReader(std::shared_ptr<NumberElementReader> numberElementReader)
{
    this->numberElementReader = numberElementReader;
}

void ElementReadersMediator::setStringElementReader(std::shared_ptr<StringElementReader> stringElementReader)
{
    this->stringElementReader = stringElementReader;
}

void ElementReadersMediator::setObjectElementReader(std::shared_ptr<ObjectElementReader> objectElementReader)
{
    this->objectElementReader = objectElementReader;
}

std::shared_ptr<BaseElement> ElementReadersMediator::call(std::shared_ptr<BaseToken> token)
{
    if (token->getType() == TOKEN::BOOLEAN && this->booleanElementReader != nullptr)
        return this->booleanElementReader->readElement(token);
    else if (token->getType() == TOKEN::ARRAY_OPEN && this->listElementReader != nullptr)
        return this->listElementReader->readElement(token);
    else if (token->getType() == TOKEN::NULL_TYPE && this->nullElementReader != nullptr)
        return this->nullElementReader->readElement(token);
    else if (token->getType() == TOKEN::NUMBER && this->numberElementReader != nullptr)
        return this->numberElementReader->readElement(token);
    else if (token->getType() == TOKEN::STRING && this->stringElementReader != nullptr)
        return this->stringElementReader->readElement(token);
    else if (token->getType() == TOKEN::CURLY_OPEN && this->objectElementReader != nullptr)
        return this->objectElementReader->readElement(token);
    else
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Unsuccessful attempt to parse token on this position."
                             "Maybe you forgot to set Reader in Mediator?");
}

ElementReadersMediator::~ElementReadersMediator()
{

}
