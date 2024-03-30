#ifndef OBJECTELEMENT_H
#define OBJECTELEMENT_H

#include "BaseElement.h"


class ObjectElement : public BaseElement
{
public:
    ObjectElement();

    std::string toString();

    ~ObjectElement();

private:
    elementType _type;
    std::shared_ptr<ElementValue> _value;
};

#endif // OBJECTELEMENT_H
