#ifndef ELEMENTREADERSMEDIATOR_H
#define ELEMENTREADERSMEDIATOR_H

#include "BaseElementReadersMediator.h"
#include "../ElementReaders/BooleanElementReader.h"
#include "../ElementReaders/ListElementReader.h"
#include "../ElementReaders/NullElementReader.h"
#include "../ElementReaders/NumberElementReader.h"
#include "../ElementReaders/StringElementReader.h"
#include "../ElementReaders/ObjectElementReader.h"
#include "../../ParseExceptions/ParseException.h"


class ElementReadersMediator : public BaseElementReadersMediator
{
public:
    ElementReadersMediator();

    std::shared_ptr<BaseElement> call(std::shared_ptr<BaseToken> token);

    void setBooleanElementReader(std::shared_ptr<BooleanElementReader> booleanElementReader);
    void setListElementReader(std::shared_ptr<ListElementReader> listElementReader);
    void setNullElementReader(std::shared_ptr<NullElementReader> nullElementReader);
    void setNumberElementReader(std::shared_ptr<NumberElementReader> numberElementReader);
    void setStringElementReader(std::shared_ptr<StringElementReader> stringElementReader);
    void setObjectElementReader(std::shared_ptr<ObjectElementReader> objectElementReader);

    ~ElementReadersMediator();

private:
    std::shared_ptr<BooleanElementReader> booleanElementReader = nullptr;
    std::shared_ptr<ListElementReader> listElementReader = nullptr;
    std::shared_ptr<NullElementReader> nullElementReader = nullptr;
    std::shared_ptr<NumberElementReader> numberElementReader = nullptr;
    std::shared_ptr<StringElementReader> stringElementReader = nullptr;
    std::shared_ptr<ObjectElementReader> objectElementReader = nullptr;
};

#endif // ELEMENTREADERSMEDIATOR_H
