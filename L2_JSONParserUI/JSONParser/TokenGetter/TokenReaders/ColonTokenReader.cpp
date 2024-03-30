#include "ColonTokenReader.h"


ColonTokenReader::ColonTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> ColonTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<ColonToken>(ColonToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    this->_file->readChar();
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::COLON);
    return token;
}

ColonTokenReader::~ColonTokenReader() {}
