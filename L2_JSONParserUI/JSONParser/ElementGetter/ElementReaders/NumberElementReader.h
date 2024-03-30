#ifndef NUMBERELEMENTREADER_H
#define NUMBERELEMENTREADER_H

#include "BaseElementReader.h"
#include "../Elements/NumberElement.h"


class NumberElementReader : BaseElementReader
{
public:
    NumberElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator);

    std::shared_ptr<BaseElement> readElement(std::shared_ptr<BaseToken> tokenTrigger);

    ~NumberElementReader();

private:
    std::shared_ptr<TokenGetter> _tokenGetter;
    std::shared_ptr<BaseElementReadersMediator> _mediator;
};

#endif // NUMBERELEMENTREADER_H
