#ifndef CURLYOPENTOKEN_H
#define CURLYOPENTOKEN_H

#include "BaseToken.h"


class CurlyOpenToken : public BaseToken
{
public:
    CurlyOpenToken ();

    std::string toString();

    ~CurlyOpenToken ();
};

#endif // CURLYOPENTOKEN_H
