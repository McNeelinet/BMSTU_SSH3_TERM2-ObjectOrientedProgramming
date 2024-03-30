#ifndef ARRAYOPENTOKENREADER_H
#define ARRAYOPENTOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/ArrayOpenToken.h"


class ArrayOpenTokenReader : public BaseTokenReader
{
public:
    ArrayOpenTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~ArrayOpenTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // ARRAYOPENTOKENREADER_H
