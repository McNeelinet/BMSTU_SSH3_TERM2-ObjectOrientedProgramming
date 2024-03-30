#ifndef BOOLEANELEMENT_H
#define BOOLEANELEMENT_H

#include "BaseElement.h"


class BooleanElement : public BaseElement
{
public:
    BooleanElement();

    std::string toString();

    ~BooleanElement();

private:
    elementType _type;
    std::shared_ptr<ElementValue> _value;
};

#endif // BOOLEANELEMENT_H
