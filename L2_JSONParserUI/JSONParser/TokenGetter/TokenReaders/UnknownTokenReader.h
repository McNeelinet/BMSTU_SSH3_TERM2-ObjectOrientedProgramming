#ifndef UNKNOWNTOKENREADER_H
#define UNKNOWNTOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/UnknownToken.h"
#include "../../ParseExceptions/ParseException.h"


class UnknownTokenReader : public BaseTokenReader
{
public:
    UnknownTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~UnknownTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // UNKNOWNTOKENREADER_H
