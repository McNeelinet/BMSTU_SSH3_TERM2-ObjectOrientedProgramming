#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "ParseResult.h"
#include "ElementGetter/ElementGetter.h"


class JSONParser
{
public:
    JSONParser(std::string filename);

    ParseResult parse();

    ~JSONParser();

private:
    std::unique_ptr<ElementGetter> _elementGetter;
    std::shared_ptr<JSONFile> _file;
};

#endif // JSONPARSER_H
