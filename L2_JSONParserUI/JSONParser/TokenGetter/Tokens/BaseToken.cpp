#include "BaseToken.h"


size_t BaseToken::getType()
{
    return this->_type;
}

std::string BaseToken::getValue()
{
    return this->_value;
}

position BaseToken::getStartPosition()
{
    return this->_startPosition;
}

void BaseToken::setType(size_t type)
{
    this->_type = type;
}

void BaseToken::setValue(std::string value)
{
    this->_value = value;
}

void BaseToken::setStartPosition(position pos)
{
    this->_startPosition = pos;
}

void BaseToken::setEndPosition(position pos)
{
    this->_endPosition = pos;
}
