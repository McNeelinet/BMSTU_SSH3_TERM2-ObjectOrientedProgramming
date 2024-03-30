#include "StringElement.h"


StringElement::StringElement()
{
    this->_type = elementType::STRING;
    this->_value = nullptr;
}

std::string StringElement::toString()
{
    if (this->_value == nullptr)
        throw std::exception();
    return std::string(*this->_value->sValue);
}

StringElement::~StringElement() {}
