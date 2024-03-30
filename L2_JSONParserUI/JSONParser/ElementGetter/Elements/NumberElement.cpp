#include "NumberElement.h"


NumberElement::NumberElement()
{
    this->_type = elementType::NUMBER;
    this->_value = nullptr;
}

std::string NumberElement::toString()
{
    if (this->_value == nullptr)
        throw std::exception();
    return std::to_string(this->_value->fValue);
}

NumberElement::~NumberElement() {}
