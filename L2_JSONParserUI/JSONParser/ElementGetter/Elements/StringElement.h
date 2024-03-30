#ifndef STRINGELEMENT_H
#define STRINGELEMENT_H

#include "BaseElement.h"


class StringElement : public BaseElement
{
public:
    StringElement();

    std::string toString();

    ~StringElement();

private:
    elementType _type;
    std::shared_ptr<ElementValue> _value;
};

#endif // STRINGELEMENT_H
