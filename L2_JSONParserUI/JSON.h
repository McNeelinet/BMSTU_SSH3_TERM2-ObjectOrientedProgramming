#ifndef JSON_H
#define JSON_H

#include "JSONParser/JSONParser.h"
#include "JSONReader/JSONReader.h"


class JSON
{
public:
    JSON(std::string filename);

    ParseResult parse();
    std::string read();

    ~JSON();

private:
    std::unique_ptr<JSONParser> _parser;
    std::unique_ptr<JSONReader> _reader;
};

#endif // JSON_H
