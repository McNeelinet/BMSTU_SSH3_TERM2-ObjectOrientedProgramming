#include "BooleanToken.h"


BooleanToken::BooleanToken() {}

std::string BooleanToken::toString()
{
    return "Boolean: " + this->getValue() + "\n";
}

BooleanToken::~BooleanToken() {}
