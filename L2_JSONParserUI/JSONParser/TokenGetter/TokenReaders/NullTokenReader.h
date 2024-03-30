#ifndef NULLTOKENREADER_H
#define NULLTOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/NullToken.h"
#include "../../ParseExceptions/ParseException.h"


class NullTokenReader : public BaseTokenReader
{
public:
    NullTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~NullTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // NULLTOKENREADER_H
