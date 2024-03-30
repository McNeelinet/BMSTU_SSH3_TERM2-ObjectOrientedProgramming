#ifndef NULLELEMENTREADER_H
#define NULLELEMENTREADER_H

#include "BaseElementReader.h"
#include "../Elements/NullElement.h"


class NullElementReader : BaseElementReader
{
public:
    NullElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator);

    std::shared_ptr<BaseElement> readElement(std::shared_ptr<BaseToken> tokenTrigger);

    ~NullElementReader();

private:
    std::shared_ptr<TokenGetter> _tokenGetter;
    std::shared_ptr<BaseElementReadersMediator> _mediator;
};

#endif // NULLELEMENTREADER_H
