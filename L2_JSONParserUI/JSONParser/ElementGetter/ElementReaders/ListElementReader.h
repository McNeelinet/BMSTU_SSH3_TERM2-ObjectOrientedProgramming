#ifndef LISTELEMENTREADER_H
#define LISTELEMENTREADER_H

#include "BaseElementReader.h"
#include "../Elements/ListElement.h"
#include "../../ParseExceptions/ParseException.h"


class ListElementReader : BaseElementReader
{
public:
    ListElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator);

    std::shared_ptr<BaseElement> readElement(std::shared_ptr<BaseToken> tokenTrigger);

    ~ListElementReader();

private:
    enum ReaderStates {
        READ_VALUE,
        READ_DELIMER,
        FINISHED
    };

    std::shared_ptr<TokenGetter> _tokenGetter;
    std::shared_ptr<BaseElementReadersMediator> _mediator;

    void checkValue(size_t& state, std::shared_ptr<BaseToken> token, std::shared_ptr<JSONList> list);
    void checkDelimer(size_t& state, std::shared_ptr<BaseToken> token);
};

#endif // LISTELEMENTREADER_H
