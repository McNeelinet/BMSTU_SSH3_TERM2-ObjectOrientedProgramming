#include "StringTokenReader.h"


StringTokenReader::StringTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> StringTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<StringToken>(StringToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    char c;
    std::string value = "";

    c = this->_file->readChar();
    value += c;
    do {
        c = this->_file->readChar();

        if (this->_file->isEnd())
            throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                                 "Quote on this position don't have a pair");
        else
            value += c;
    }
    while (c != '"');

    token->setValue(value);
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::STRING);
    return token;
}

StringTokenReader::~StringTokenReader() {}
