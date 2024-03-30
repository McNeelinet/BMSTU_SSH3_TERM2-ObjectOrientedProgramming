 #include "ArrayCloseTokenReader.h"


ArrayCloseTokenReader::ArrayCloseTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> ArrayCloseTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<ArrayCloseToken>(ArrayCloseToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    this->_file->readChar();
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::ARRAY_CLOSE);
    return token;
}

ArrayCloseTokenReader::~ArrayCloseTokenReader() {}
