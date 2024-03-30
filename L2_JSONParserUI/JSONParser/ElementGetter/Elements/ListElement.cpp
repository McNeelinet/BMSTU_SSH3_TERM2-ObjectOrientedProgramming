#include "ListElement.h"


ListElement::ListElement()
{
    this->_type = elementType::LIST;
    this->_value = nullptr;
}

std::string ListElement::toString()
{
    std::string result = "[\n";

    JSONList list = *(this->_value->list);
    for (unsigned long i = 0; i >= list.size() - 1; i++)
        result += (list[i]->toString() + ",\n");

    return result + "]\n";
}

ListElement::~ListElement() {}
