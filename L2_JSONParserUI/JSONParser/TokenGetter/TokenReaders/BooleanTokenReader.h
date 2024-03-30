#ifndef BOOLEANTOKENREADER_H
#define BOOLEANTOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/BooleanToken.h"
#include "../../ParseExceptions/ParseException.h"


class BooleanTokenReader : public BaseTokenReader
{
public:
    BooleanTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~BooleanTokenReader();

private:
    std::shared_ptr<BaseToken> readTrue();
    std::shared_ptr<BaseToken> readFalse();

    std::shared_ptr<JSONFile> _file;
};

#endif // BOOLEANTOKENREADER_H
