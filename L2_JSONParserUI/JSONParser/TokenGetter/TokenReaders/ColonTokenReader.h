#ifndef COLONTOKENREADER_H
#define COLONTOKENREADER_H

#include "BaseTokenReader.h"
#include "../Tokens/ColonToken.h"


class ColonTokenReader : public BaseTokenReader
{
public:
    ColonTokenReader(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> readToken();

    ~ColonTokenReader();

private:
    std::shared_ptr<JSONFile> _file;
};

#endif // COLONTOKENREADER_H
