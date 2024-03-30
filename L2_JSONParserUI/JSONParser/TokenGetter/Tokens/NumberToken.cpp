#include "NumberToken.h"


NumberToken::NumberToken() {}

std::string NumberToken::toString()
{
    return "Number: " + this->getValue() + "\n";
}

NumberToken::~NumberToken() {}
