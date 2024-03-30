#ifndef LISTELEMENT_H
#define LISTELEMENT_H

#include "BaseElement.h"


class ListElement : public BaseElement
{
public:
    ListElement();

    std::string toString();

    ~ListElement();

private:
    elementType _type;
    std::shared_ptr<ElementValue> _value;
};

#endif // LISTELEMENT_H
