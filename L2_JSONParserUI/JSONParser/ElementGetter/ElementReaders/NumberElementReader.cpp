#include "NumberElementReader.h"


NumberElementReader::NumberElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator) : _tokenGetter(tokenGetter), _mediator(mediator)
{

}

std::shared_ptr<BaseElement> NumberElementReader::readElement(std::shared_ptr<BaseToken> tokenTrigger)
{
    std::shared_ptr<BaseElement> element = std::make_shared<NumberElement>(NumberElement());
    std::shared_ptr<ElementValue> value = std::make_shared<ElementValue>();

    value->type = elementValueType::FLOAT;
    value->fValue = std::stof(tokenTrigger->getValue());

    element->setValue(value);

    return element;
}

NumberElementReader::~NumberElementReader()
{

}
