#include "TokenGetter.h"


TokenGetter::TokenGetter(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::unique_ptr<BaseTokenReader> TokenGetter::chooseReader(char c)
{
    if (c == '"')
        return std::make_unique<StringTokenReader>(StringTokenReader(this->_file));
    else if (c=='-' || (c >= '0' && c <= '9'))
        return std::make_unique<NumberTokenReader>(NumberTokenReader(this->_file));
    else if (c == 't' || c == 'f')
        return std::make_unique<BooleanTokenReader>(BooleanTokenReader(this->_file));
    else if (c == 'n')
        return std::make_unique<NullTokenReader>(NullTokenReader(this->_file));
    else if (c == '{')
        return std::make_unique<CurlyOpenTokenReader>(CurlyOpenTokenReader(this->_file));
    else if (c == '}')
        return std::make_unique<CurlyCloseTokenReader>(CurlyCloseTokenReader(this->_file));
    else if (c == '[')
        return std::make_unique<ArrayOpenTokenReader>(ArrayOpenTokenReader(this->_file));
    else if (c == ']')
        return std::make_unique<ArrayCloseTokenReader>(ArrayCloseTokenReader(this->_file));
    else if (c == ':')
        return std::make_unique<ColonTokenReader>(ColonTokenReader(this->_file));
    else if (c == ',')
        return std::make_unique<CommaTokenReader>(CommaTokenReader(this->_file));
    else
        return std::make_unique<UnknownTokenReader>(UnknownTokenReader(this->_file));
}

std::shared_ptr<BaseToken> TokenGetter::getToken()
{
    char c = this->_file->readCharSkipSpaces();
    std::unique_ptr<BaseTokenReader> reader = this->chooseReader(c);
    std::shared_ptr<BaseToken> token = reader->readToken();

    return token;
}

TokenGetter::~TokenGetter()
{

}
