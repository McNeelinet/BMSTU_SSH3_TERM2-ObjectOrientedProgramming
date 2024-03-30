#ifndef BOOLEANTOKEN_H
#define BOOLEANTOKEN_H

#include "BaseToken.h"


class BooleanToken : public BaseToken
{
public:
    BooleanToken();

    std::string toString();

    ~BooleanToken();
};

#endif // BOOLEANTOKEN_H
