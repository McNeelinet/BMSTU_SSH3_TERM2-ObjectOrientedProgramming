#ifndef CURLYCLOSETOKEN_H
#define CURLYCLOSETOKEN_H

#include "BaseToken.h"


class CurlyCloseToken : public BaseToken
{
public:
    CurlyCloseToken ();

    std::string toString();

    ~CurlyCloseToken ();
};

#endif // CURLYCLOSETOKEN_H
