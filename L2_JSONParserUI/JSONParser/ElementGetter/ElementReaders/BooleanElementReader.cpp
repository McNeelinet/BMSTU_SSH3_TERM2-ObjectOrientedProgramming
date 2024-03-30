 #include "BooleanElementReader.h"


BooleanElementReader::BooleanElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator) : _tokenGetter(tokenGetter), _mediator(mediator)
{

}

std::shared_ptr<BaseElement> BooleanElementReader::readElement(std::shared_ptr<BaseToken> tokenTrigger)
{
    std::shared_ptr<BaseElement> element = std::make_shared<BooleanElement>(BooleanElement());
    std::shared_ptr<ElementValue> value = std::make_shared<ElementValue>();

    value->type = elementValueType::BOOLEAN;
    if (tokenTrigger->getValue() == "True")
        value->bValue = true;
    else if (tokenTrigger->getValue() == "False")
        value->bValue = false;

    element->setValue(value);

    return element;
}

BooleanElementReader::~BooleanElementReader()
{

}
