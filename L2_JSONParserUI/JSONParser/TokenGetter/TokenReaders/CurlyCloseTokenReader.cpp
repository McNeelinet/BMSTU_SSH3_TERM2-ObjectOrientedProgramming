#include "CurlyCloseTokenReader.h"


CurlyCloseTokenReader::CurlyCloseTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> CurlyCloseTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<CurlyCloseToken>(CurlyCloseToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    this->_file->readChar();
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::CURLY_CLOSE);
    return token;
}

CurlyCloseTokenReader::~CurlyCloseTokenReader() {}
