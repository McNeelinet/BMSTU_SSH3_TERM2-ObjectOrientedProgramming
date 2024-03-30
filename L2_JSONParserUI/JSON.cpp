#include "JSON.h"


JSON::JSON(std::string filename)
{
    this->_parser = std::unique_ptr<JSONParser>(new JSONParser(filename));
    this->_reader = std::unique_ptr<JSONReader>(new JSONReader(filename));
}

ParseResult JSON::parse()
{
    return this->_parser->parse();
}

std::string JSON::read()
{
    return this->_reader->readAll();
}

JSON::~JSON()
{

}
