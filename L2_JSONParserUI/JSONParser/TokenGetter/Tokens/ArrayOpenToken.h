#ifndef ARRAYOPENTOKEN_H
#define ARRAYOPENTOKEN_H

#include "BaseToken.h"


class ArrayOpenToken : public BaseToken
{
public:
    ArrayOpenToken ();

    std::string toString();

    ~ArrayOpenToken ();
};

#endif // ARRAYOPENTOKEN_H
