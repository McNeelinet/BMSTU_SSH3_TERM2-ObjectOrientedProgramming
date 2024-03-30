#include "NullElement.h"


NullElement::NullElement()
{
    this->_type = elementType::NULL_TYPE;
    this->_value = nullptr;
}

std::string NullElement::toString()
{
    if (this->_value == nullptr)
        throw std::exception();
    return "null";
}

NullElement::~NullElement() {}
