#include "StringElementReader.h"


StringElementReader::StringElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator) : _tokenGetter(tokenGetter), _mediator(mediator)
{

}

std::shared_ptr<BaseElement> StringElementReader::readElement(std::shared_ptr<BaseToken> tokenTrigger)
{
    std::shared_ptr<BaseElement> element = std::make_shared<StringElement>(StringElement());
    std::shared_ptr<ElementValue> value = std::make_shared<ElementValue>();

    value->type = elementValueType::STRING;
    value->sValue = std::make_shared<std::string>(std::string(tokenTrigger->getValue()));

    element->setValue(value);

    return element;
}

StringElementReader::~StringElementReader()
{

}
