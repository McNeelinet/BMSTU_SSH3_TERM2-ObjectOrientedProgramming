#include "ParseResult.h"


bool ParseResult::isSuccess()
{
    return this->_status;
}

std::string ParseResult::getPrettyErrorText()
{
    if (this->_parseException != nullptr)
        return "[" + std::to_string(this->_parseException->getErrorLocation().errorLine) +
               ":" + std::to_string(this->_parseException->getErrorLocation().errorColumn) +
               "] " + this->_parseException->getErrorText() + "\n";
    else
        return "Everything is OK!\n";
}

void ParseResult::setParseException(std::shared_ptr<ParseException> parseException)
{
    this->_status = false;
    this->_parseException = parseException;
}

void ParseResult::setRootElement(std::shared_ptr<BaseElement> _rootElement)
{
    this->_status = true;
    this->_rootElement = _rootElement;
}
