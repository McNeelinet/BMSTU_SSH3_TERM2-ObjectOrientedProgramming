#include "NullTokenReader.h"


NullTokenReader::NullTokenReader(std::shared_ptr<JSONFile> file) : _file(file)
{

}

std::shared_ptr<BaseToken> NullTokenReader::readToken()
{
    std::shared_ptr<BaseToken> token = std::make_shared<NullToken>(NullToken());

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

    if (value != "null") {
        throw ParseException(token->getStartPosition().line, token->getStartPosition().column,
                             "Got Unknown token");
    }

    token->setValue(value);
    token->setEndPosition(this->_file->getCurrentPosition());

    token->setType(TOKEN::NULL_TYPE);
    return token;
}

NullTokenReader::~NullTokenReader() {}
