 #include "ParseException.h"


ParseException::ParseException(size_t errorLine, size_t errorColumn, std::string errorText)
{
    this->_errorLocation = {.errorLine = errorLine, .errorColumn = errorColumn};
    this->_errorText = errorText;
}

errorLocation ParseException::getErrorLocation()
{
    return this->_errorLocation;
}

std::string ParseException::getErrorText()
{
    return this->_errorText;
}
