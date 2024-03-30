#ifndef PARSERESULT_H
#define PARSERESULT_H

#include <memory>
#include "ElementGetter/Elements/BaseElement.h"
#include "ParseExceptions/ParseException.h"


class ParseResult
{
public:
    bool isSuccess();

    std::string getPrettyErrorText();

    void setParseException(std::shared_ptr<ParseException> parseException);
    void setRootElement(std::shared_ptr<BaseElement> _rootElement);

private:
    bool _status;
    std::shared_ptr<BaseElement> _rootElement = nullptr;
    std::shared_ptr<ParseException> _parseException = nullptr;
};

#endif // PARSERESULT_H
