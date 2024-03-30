#ifndef ELEMENTGETTER_H
#define ELEMENTGETTER_H

#include <memory>
#include "Elements/BaseElement.h"
#include "ElementReadersMediators/ElementReadersMediator.h"
#include "../JSONFile.h"
#include "../TokenGetter/TokenGetter.h"


class ElementGetter
{
public:
    ElementGetter(std::shared_ptr<JSONFile> file);

    std::shared_ptr<BaseElement> getElement();

    ~ElementGetter();

private:
    std::shared_ptr<JSONFile> _file;
    std::shared_ptr<TokenGetter> _tokenGetter;
    std::shared_ptr<ElementReadersMediator> _mediator;
};

#endif // ELEMENTGETTER_H
