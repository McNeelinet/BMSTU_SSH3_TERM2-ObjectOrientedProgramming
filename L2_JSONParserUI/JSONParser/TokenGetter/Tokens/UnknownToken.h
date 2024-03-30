#ifndef UNKNOWNTOKEN_H
#define UNKNOWNTOKEN_H


#include "BaseToken.h"


class UnknownToken : public BaseToken
{
public:
    UnknownToken ();

    std::string toString();

    ~UnknownToken ();
};

#endif // UNKNOWNTOKEN_H
