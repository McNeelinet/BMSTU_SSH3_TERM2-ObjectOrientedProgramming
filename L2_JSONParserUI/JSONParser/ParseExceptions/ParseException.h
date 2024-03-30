#ifndef PARSEEXCEPTION_H
#define PARSEEXCEPTION_H

#include <exception>
#include <string>


struct errorLocation
{
    size_t errorLine;
    size_t errorColumn;
};

class ParseException : std::exception
{
public:
    ParseException(size_t errorLine, size_t errorColumn, std::string errorText);

    errorLocation getErrorLocation();
    std::string getErrorText();

    ~ParseException() {};

private:
    errorLocation _errorLocation;
    std::string _errorText;
};

#endif // PARSEEXCEPTION_H
