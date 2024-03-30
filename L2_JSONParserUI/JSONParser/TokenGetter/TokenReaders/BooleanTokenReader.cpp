#include "BooleanTokenReader.h"


BooleanTokenReader::BooleanTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> BooleanTokenReader::readTrue()
{
    std::shared_ptr<BaseToken> token = std::make_shared<BooleanToken>(BooleanToken());
    token->setType(TOKEN::BOOLEAN);

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    std::string value = "";
    char c;

    for (int i = 0; i <= 3; i++) {
        c = this->_file->readChar();
        if (this->_file->isEnd())
            break;
        else
            value += c;
    }

    if (value == "true")
        token->setValue("True");
    else
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Got Unknown token");

    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::BOOLEAN);
    return token;
}

std::shared_ptr<BaseToken> BooleanTokenReader::readFalse()
{
    std::shared_ptr<BaseToken> token = std::make_shared<BooleanToken>(BooleanToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    std::string value = "";
    char c;

    for (int i = 0; i <= 4; i++) {
        c = this->_file->readChar();
        if (this->_file->isEnd())
            break;
        else
            value += c;
    }

    if (value == "false")
        token->setValue("False");
    else
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Got Unknown token");

    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::BOOLEAN);
    return token;
}

std::shared_ptr<BaseToken> BooleanTokenReader::readToken()
{
    char c;
    this->_file->rollBack();
    c = this->_file->readChar();
    if (c == 'f')
        return readFalse();
    else
        return readTrue();
}

BooleanTokenReader::~BooleanTokenReader() {}
