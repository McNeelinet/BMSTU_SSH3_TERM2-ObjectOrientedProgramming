#ifndef NUMBERELEMENT_H
#define NUMBERELEMENT_H

#include "BaseElement.h"


class NumberElement : public BaseElement
{
public:
    NumberElement();

    std::string toString();

    ~NumberElement();

private:
    elementType _type;
    std::shared_ptr<ElementValue> _value;
};

#endif // NUMBERELEMENT_H
