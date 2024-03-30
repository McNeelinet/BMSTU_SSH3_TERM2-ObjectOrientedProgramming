#ifndef OBJECTELEMENTREADER_H
#define OBJECTELEMENTREADER_H

#include "BaseElementReader.h"
#include "../Elements/ObjectElement.h"
#include "../../ParseExceptions/ParseException.h"


class ObjectElementReader : BaseElementReader
{
public:
    ObjectElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator);

    std::shared_ptr<BaseElement> readElement(std::shared_ptr<BaseToken> tokenTrigger);

    ~ObjectElementReader();

private:
    enum ReaderStates {
        READ_KEY,
        READ_COLON,
        READ_VALUE,
        READ_DELIMER,
        FINISHED
    };

    std::shared_ptr<TokenGetter> _tokenGetter;
    std::shared_ptr<BaseElementReadersMediator> _mediator;

    std::string checkKey(size_t& state, std::shared_ptr<BaseToken> token, std::shared_ptr<JSONObject> object);
    void checkColon(size_t& state, std::shared_ptr<BaseToken> token);
    std::shared_ptr<BaseElement> checkValue(size_t& state, std::shared_ptr<BaseToken> token);
    void checkDelimer(size_t& state, std::shared_ptr<BaseToken> token);
};

#endif // OBJECTELEMENTREADER_H
