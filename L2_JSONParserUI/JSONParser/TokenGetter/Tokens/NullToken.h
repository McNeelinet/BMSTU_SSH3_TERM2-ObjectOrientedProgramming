#ifndef NULLTOKEN_H
#define NULLTOKEN_H

#include "BaseToken.h"


class NullToken : public BaseToken
{
public:
    NullToken ();

    std::string toString();

    ~NullToken ();
};

#endif // NULLTOKEN_H
