#ifndef ARRAYCLOSETOKEN_H
#define ARRAYCLOSETOKEN_H

#include "BaseToken.h"


class ArrayCloseToken : public BaseToken
{
public:
    ArrayCloseToken ();

    std::string toString();

    ~ArrayCloseToken ();
};

#endif // ARRAYCLOSETOKEN_H
