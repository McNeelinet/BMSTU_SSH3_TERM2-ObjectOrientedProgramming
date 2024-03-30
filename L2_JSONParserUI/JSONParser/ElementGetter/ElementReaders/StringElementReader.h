#ifndef STRINGELEMENTREADER_H
#define STRINGELEMENTREADER_H

#include "BaseElementReader.h"
#include "../Elements/StringElement.h"


class StringElementReader : BaseElementReader
{
public:
    StringElementReader(std::shared_ptr<TokenGetter> tokenGetter, std::shared_ptr<BaseElementReadersMediator> mediator);

    std::shared_ptr<BaseElement> readElement(std::shared_ptr<BaseToken> tokenTrigger);

    ~StringElementReader();

private:
    std::shared_ptr<TokenGetter> _tokenGetter;
    std::shared_ptr<BaseElementReadersMediator> _mediator;
};

#endif // STRINGELEMENTREADER_H
