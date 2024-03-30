#include "JSONParser.h"


JSONParser::JSONParser(std::string filename)
{
    this->_file = std::shared_ptr<JSONFile>(new JSONFile(filename));
    this->_elementGetter = std::make_unique<ElementGetter>(ElementGetter(this->_file));
}

ParseResult JSONParser::parse()
{
    ParseResult result;
    std::shared_ptr<BaseElement> rootElement = nullptr;

    try {
        rootElement = this->_elementGetter->getElement();
    } catch(ParseException& e) {
        result.setParseException(std::make_shared<ParseException>(e));

        return result;
    }

    try {
        this->_file->readCharSkipSpaces();
    } catch(std::ios_base::failure& e) {
        result.setRootElement(rootElement);

        return result;
    }

    this->_file->rollBack();
    result.setParseException(std::make_shared<ParseException>(ParseException(this->_file->getCurrentPosition().line,
                                                                             this->_file->getCurrentPosition().column,
                                                                             "Unexpected non-whitespace symbol")));

    return result;
}

JSONParser::~JSONParser()
{

}
