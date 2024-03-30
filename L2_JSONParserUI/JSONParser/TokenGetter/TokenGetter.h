#ifndef TOKENGETTER_H
#define TOKENGETTER_H

#include "Tokens.h"
#include "TokenReaders.h"


class TokenGetter
{
public:
    TokenGetter (std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseToken> getToken();

    ~TokenGetter();
private:
    std::unique_ptr<BaseTokenReader> chooseReader(char c);

    std::shared_ptr<JSONFile> _file;
};

#endif // TOKENGETTER_H
