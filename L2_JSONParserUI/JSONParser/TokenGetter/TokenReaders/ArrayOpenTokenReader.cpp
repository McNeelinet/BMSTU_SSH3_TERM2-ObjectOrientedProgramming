#include "ArrayOpenTokenReader.h"


ArrayOpenTokenReader::ArrayOpenTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> ArrayOpenTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<ArrayOpenToken>(ArrayOpenToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    this->_file->readChar();
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::ARRAY_OPEN);
    return token;
}

ArrayOpenTokenReader::~ArrayOpenTokenReader() {}
