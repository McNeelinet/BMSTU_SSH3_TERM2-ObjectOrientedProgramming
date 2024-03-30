#ifndef STRINGTOKENREADER_H
#define STRINGTOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/StringToken.h"
#include "../../ParseExceptions/ParseException.h"


class StringTokenReader : public BaseTokenReader
{
public:
    StringTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~StringTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // STRINGTOKENREADER_H
