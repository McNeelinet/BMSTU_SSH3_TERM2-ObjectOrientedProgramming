#ifndef CURLYCLOSETOKENREADER_H
#define CURLYCLOSETOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/CurlyCloseToken.h"


class CurlyCloseTokenReader : public BaseTokenReader
{
public:
    CurlyCloseTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~CurlyCloseTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // CURLYCLOSETOKENREADER_H
