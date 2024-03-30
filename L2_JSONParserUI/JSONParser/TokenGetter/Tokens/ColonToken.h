#ifndef COLONTOKEN_H
#define COLONTOKEN_H

#include "BaseToken.h"


class ColonToken : public BaseToken
{
public:
    ColonToken ();

    std::string toString();

    ~ColonToken ();
};

#endif // COLONTOKEN_H
