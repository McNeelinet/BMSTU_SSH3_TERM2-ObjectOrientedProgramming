#ifndef BASETOKEN_H
#define BASETOKEN_H

#include "../../JSONFile.h"


enum TOKEN
{
    CURLY_OPEN,
    CURLY_CLOSE,
    COLON,
    STRING,
    NUMBER,
    ARRAY_OPEN,
    ARRAY_CLOSE,
    COMMA,
    BOOLEAN,
    NULL_TYPE,
    UNKNOWN
};

class BaseToken
{
public:
    virtual size_t getType();
    virtual std::string getValue();
    virtual position getStartPosition();

    virtual void setType(size_t type);
    virtual void setValue(std::string value);
    virtual void setStartPosition(position pos);
    virtual void setEndPosition(position pos);

    virtual std::string toString() = 0;

private:
    size_t _type;
    std::string _value;

    position _startPosition;
    position _endPosition;
};

#endif // BASETOKEN_H
