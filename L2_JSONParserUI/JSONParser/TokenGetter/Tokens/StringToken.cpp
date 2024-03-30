#include "StringToken.h"


StringToken::StringToken() {}

std::string StringToken::toString()
{
    return "String: " + this->getValue() + "\n";
}

StringToken::~StringToken() {}
