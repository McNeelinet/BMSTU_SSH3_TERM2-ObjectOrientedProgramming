#ifndef COMMATOKENREADER_H
#define COMMATOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/CommaToken.h"


class CommaTokenReader : public BaseTokenReader
{
public:
    CommaTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~CommaTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // COMMATOKENREADER_H
