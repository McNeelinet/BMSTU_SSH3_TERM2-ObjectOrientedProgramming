#include "ObjectElement.h"


ObjectElement::ObjectElement()
{
    this->_type = elementType::OBJECT;
    this->_value = nullptr;
}

std::string ObjectElement::toString()
{
    return "object";
}

ObjectElement::~ObjectElement() {}
