 #include "ElementGetter.h"


ElementGetter::ElementGetter(std::shared_ptr<JSONFile> file) : _file(file)
{
    this->_tokenGetter = std::make_shared<TokenGetter>(TokenGetter(this->_file));
    this->_mediator = std::make_shared<ElementReadersMediator>(ElementReadersMediator());

    this->_mediator->setBooleanElementReader(std::make_shared<BooleanElementReader>(BooleanElementReader(this->_tokenGetter, this->_mediator)));
    this->_mediator->setNullElementReader(std::make_shared<NullElementReader>(NullElementReader(this->_tokenGetter, this->_mediator)));
    this->_mediator->setNumberElementReader(std::make_shared<NumberElementReader>(NumberElementReader(this->_tokenGetter, this->_mediator)));
    this->_mediator->setStringElementReader(std::make_shared<StringElementReader>(StringElementReader(this->_tokenGetter, this->_mediator)));
    this->_mediator->setListElementReader(std::make_shared<ListElementReader>(ListElementReader(this->_tokenGetter, this->_mediator)));
    this->_mediator->setObjectElementReader(std::make_shared<ObjectElementReader>(ObjectElementReader(this->_tokenGetter, this->_mediator)));
}

std::shared_ptr<BaseElement> ElementGetter::getElement()
{
    std::shared_ptr<BaseToken> token = _tokenGetter->getToken();

    return this->_mediator->call(token);
}

ElementGetter::~ElementGetter() {}
