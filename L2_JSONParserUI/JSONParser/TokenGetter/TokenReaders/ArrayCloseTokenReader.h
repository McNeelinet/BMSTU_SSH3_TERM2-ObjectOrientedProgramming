#ifndef ARRAYCLOSETOKENREADER_H
#define ARRAYCLOSETOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/ArrayCloseToken.h"


class ArrayCloseTokenReader : public BaseTokenReader
{
public:
    ArrayCloseTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~ArrayCloseTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // ARRAYCLOSETOKENREADER_H
