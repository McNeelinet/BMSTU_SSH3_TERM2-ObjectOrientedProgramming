 #include "BaseElement.h"


elementType BaseElement::getType()
{
    return this->_type;
}

void BaseElement::setValue(std::shared_ptr<ElementValue> value)
{
    this->_value = value;
}

std::shared_ptr<ElementValue> BaseElement::getValue()
{
    return this->_value;
}
