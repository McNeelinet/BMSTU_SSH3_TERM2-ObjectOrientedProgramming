#include "CommaTokenReader.h"


CommaTokenReader::CommaTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> CommaTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<CommaToken>(CommaToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    this->_file->readChar();
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::COMMA);
    return token;
}

CommaTokenReader::~CommaTokenReader() {}
