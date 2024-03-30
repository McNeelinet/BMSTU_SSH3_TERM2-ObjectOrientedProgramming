#ifndef NULLELEMENT_H
#define NULLELEMENT_H

#include "BaseElement.h"


class NullElement : public BaseElement
{
public:
    NullElement();

    std::string toString();

    ~NullElement();

private:
    elementType _type;
    std::shared_ptr<ElementValue> _value;
};

#endif // NULLELEMENT_H
