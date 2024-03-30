#ifndef BASEELEMENTREADERSMEDIATOR_H
#define BASEELEMENTREADERSMEDIATOR_H

#include <memory>
#include "../Elements/BaseElement.h"
#include "../../TokenGetter/Tokens/BaseToken.h"


class BooleanElementReader;
class ListElementReader;
class NullElementReader;
class NumberElementReader;
class StringElementReader;

class BaseElementReadersMediator
{
public:
    virtual std::shared_ptr<BaseElement> call(std::shared_ptr<BaseToken> token) = 0;

    virtual ~BaseElementReadersMediator() {};

private:
    std::shared_ptr<BooleanElementReader> booleanElementReader;
    std::shared_ptr<ListElementReader> listElementReader;
    std::shared_ptr<NullElementReader> nullElementReader;
    std::shared_ptr<NumberElementReader> numberElementReader;
    std::shared_ptr<StringElementReader> stringElementReader;
};

#endif // BASEELEMENTREADERSMEDIATOR_H
