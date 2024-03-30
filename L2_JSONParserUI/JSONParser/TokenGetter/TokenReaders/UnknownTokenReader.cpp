#include "UnknownTokenReader.h"


UnknownTokenReader::UnknownTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> UnknownTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<UnknownToken>(UnknownToken());

    this->_file->rollBack();
    token->setStartPosition(this->_file->getCurrentPosition());

    throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                         "Got Unknown token");

    token->setType(TOKEN::UNKNOWN);
    return token;
}

UnknownTokenReader::~UnknownTokenReader() {}
