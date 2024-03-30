#ifndef BASEELEMENTREADER_H
#define BASEELEMENTREADER_H

#include <memory>
#include "../Elements/BaseElement.h"
#include "../ElementReadersMediators/BaseElementReadersMediator.h"
#include "../../TokenGetter/TokenGetter.h"


class BaseElementReader
{
public:
    virtual std::shared_ptr<BaseElement> readElement(std::shared_ptr<BaseToken>) = 0;

    virtual ~BaseElementReader() {}
};

#endif // BASEELEMENTREADER_H
