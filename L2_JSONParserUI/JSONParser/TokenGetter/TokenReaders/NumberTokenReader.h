#ifndef NUMBERTOKENREADER_H
#define NUMBERTOKENREADER_H


#include "BaseTokenReader.h"
#include "../Tokens/NumberToken.h"


class NumberTokenReader : public BaseTokenReader
{
public:
    NumberTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~NumberTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // NUMBERTOKENREADER_H
