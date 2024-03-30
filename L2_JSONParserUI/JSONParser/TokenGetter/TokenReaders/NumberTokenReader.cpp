#include "NumberTokenReader.h"


NumberTokenReader::NumberTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> NumberTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<NumberToken>(NumberToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    char c;
    std::string value = "";

    do {
        c = this->_file->readChar();

        if (this->_file->isEnd())
            break;
        else if ((c=='-')||(c >= '0' && c <= '9'))
            value += c;
        else
            this->_file->rollBack();
    } while ((c=='-')||(c >= '0' && c <= '9'));

    token->setValue(value);
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::NUMBER);
    return token;
}

NumberTokenReader::~NumberTokenReader() {}
