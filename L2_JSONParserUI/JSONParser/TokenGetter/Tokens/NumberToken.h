#ifndef NUMBERTOKEN_H
#define NUMBERTOKEN_H


#include "BaseToken.h"


class NumberToken : public BaseToken
{
public:
    NumberToken ();

    std::string toString();

    ~NumberToken ();
};

#endif // NUMBERTOKEN_H
