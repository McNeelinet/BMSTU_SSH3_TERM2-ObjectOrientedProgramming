#ifndef STRINGTOKEN_H
#define STRINGTOKEN_H

#include "BaseToken.h"


class StringToken : public BaseToken
{
public:
    StringToken ();

    std::string toString();

    ~StringToken ();
};

#endif // STRINGTOKEN_H
