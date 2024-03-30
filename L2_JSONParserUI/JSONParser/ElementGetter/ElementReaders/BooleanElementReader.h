#ifndef BOOLEANELEMENTREADER_H
#define BOOLEANELEMENTREADER_H

#include "BaseElementReader.h"
#include "../Elements/BooleanElement.h"


class BooleanElementReader : BaseElementReader
{
public:
    BooleanElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator);

    std::shared_ptr<BaseElement> readElement(std::shared_ptr<BaseToken> tokenTrigger);

    ~BooleanElementReader();

private:
    std::shared_ptr<TokenGetter> _tokenGetter;
    std::shared_ptr<BaseElementReadersMediator> _mediator;
};

#endif // BOOLEANELEMENTREADER_H
