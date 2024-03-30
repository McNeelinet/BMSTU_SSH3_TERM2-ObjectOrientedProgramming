#ifndef BASETOKENREADER_H
#define BASETOKENREADER_H

#include <memory>
#include "../Tokens/BaseToken.h"
#include "../../JSONFile.h"


class BaseTokenReader
{
public:
    virtual std::shared_ptr<BaseToken> readToken() = 0;

    virtual ~BaseTokenReader() {};
};

#endif // BASETOKENREADER_H
