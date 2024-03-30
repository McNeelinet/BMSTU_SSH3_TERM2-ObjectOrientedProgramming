#include "BooleanElement.h"


BooleanElement::BooleanElement()
{
    this->_type = elementType::BOOLEAN;
    this->_value = nullptr;
}

std::string BooleanElement::toString()
{
    if (this->_value == nullptr)
        throw std::exception();
    return (this->_value->bValue ? "true" : "false");
}

BooleanElement::~BooleanElement() {}
