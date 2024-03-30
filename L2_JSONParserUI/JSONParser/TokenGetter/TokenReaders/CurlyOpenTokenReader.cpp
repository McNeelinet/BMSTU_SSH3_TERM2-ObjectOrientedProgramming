#include "CurlyOpenTokenReader.h"


CurlyOpenTokenReader::CurlyOpenTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> CurlyOpenTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<CurlyOpenToken>(CurlyOpenToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    this->_file->readChar();
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::CURLY_OPEN);
    return token;
}

CurlyOpenTokenReader::~CurlyOpenTokenReader() {}
