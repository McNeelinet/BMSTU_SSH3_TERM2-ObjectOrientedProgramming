#ifndef COMMATOKEN_H
#define COMMATOKEN_H

#include "BaseToken.h"


class CommaToken : public BaseToken
{
public:
    CommaToken ();

    std::string toString();

    ~CommaToken ();
};

#endif // COMMATOKEN_H
