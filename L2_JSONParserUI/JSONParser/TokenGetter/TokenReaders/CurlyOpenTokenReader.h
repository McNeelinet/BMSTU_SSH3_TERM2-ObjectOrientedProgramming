#ifndef CURLYOPENTOKENREADER_H
#define CURLYOPENTOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/CurlyOpenToken.h"


class CurlyOpenTokenReader : public BaseTokenReader
{
public:
    CurlyOpenTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~CurlyOpenTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // CURLYOPENTOKENREADER_H
