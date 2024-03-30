QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    JSON.cpp \
    JSONParser/ElementGetter/ElementGetter.cpp \
    JSONParser/ElementGetter/ElementReaders/BooleanElementReader.cpp \
    JSONParser/ElementGetter/ElementReaders/ListElementReader.cpp \
    JSONParser/ElementGetter/ElementReaders/NullElementReader.cpp \
    JSONParser/ElementGetter/ElementReaders/NumberElementReader.cpp \
    JSONParser/ElementGetter/ElementReaders/ObjectElementReader.cpp \
    JSONParser/ElementGetter/ElementReaders/StringElementReader.cpp \
    JSONParser/ElementGetter/ElementReadersMediators/ElementReadersMediator.cpp \
    JSONParser/ElementGetter/Elements/BaseElement.cpp \
    JSONParser/ElementGetter/Elements/BooleanElement.cpp \
    JSONParser/ElementGetter/Elements/ListElement.cpp \
    JSONParser/ElementGetter/Elements/NullElement.cpp \
    JSONParser/ElementGetter/Elements/NumberElement.cpp \
    JSONParser/ElementGetter/Elements/ObjectElement.cpp \
    JSONParser/ElementGetter/Elements/StringElement.cpp \
    JSONParser/JSONFile.cpp \
    JSONParser/JSONParser.cpp \
    JSONParser/ParseExceptions/ParseException.cpp \
    JSONParser/ParseResult.cpp \
    JSONParser/TokenGetter/TokenGetter.cpp \
    JSONParser/TokenGetter/TokenReaders/ArrayCloseTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/ArrayOpenTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/BooleanTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/ColonTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/CommaTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/CurlyCloseTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/CurlyOpenTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/NullTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/NumberTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/StringTokenReader.cpp \
    JSONParser/TokenGetter/TokenReaders/UnknownTokenReader.cpp \
    JSONParser/TokenGetter/Tokens/ArrayCloseToken.cpp \
    JSONParser/TokenGetter/Tokens/ArrayOpenToken.cpp \
    JSONParser/TokenGetter/Tokens/BaseToken.cpp \
    JSONParser/TokenGetter/Tokens/BooleanToken.cpp \
    JSONParser/TokenGetter/Tokens/ColonToken.cpp \
    JSONParser/TokenGetter/Tokens/CommaToken.cpp \
    JSONParser/TokenGetter/Tokens/CurlyCloseToken.cpp \
    JSONParser/TokenGetter/Tokens/CurlyOpenToken.cpp \
    JSONParser/TokenGetter/Tokens/NullToken.cpp \
    JSONParser/TokenGetter/Tokens/NumberToken.cpp \
    JSONParser/TokenGetter/Tokens/StringToken.cpp \
    JSONParser/TokenGetter/Tokens/UnknownToken.cpp \
    JSONReader/JSONReader.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    JSON.h \
    JSONParser/ElementGetter/ElementGetter.h \
    JSONParser/ElementGetter/ElementReaders/BaseElementReader.h \
    JSONParser/ElementGetter/ElementReaders/BooleanElementReader.h \
    JSONParser/ElementGetter/ElementReaders/ListElementReader.h \
    JSONParser/ElementGetter/ElementReaders/NullElementReader.h \
    JSONParser/ElementGetter/ElementReaders/NumberElementReader.h \
    JSONParser/ElementGetter/ElementReaders/ObjectElementReader.h \
    JSONParser/ElementGetter/ElementReaders/StringElementReader.h \
    JSONParser/ElementGetter/ElementReadersMediators/BaseElementReadersMediator.h \
    JSONParser/ElementGetter/ElementReadersMediators/ElementReadersMediator.h \
    JSONParser/ElementGetter/Elements/BaseElement.h \
    JSONParser/ElementGetter/Elements/BooleanElement.h \
    JSONParser/ElementGetter/Elements/ListElement.h \
    JSONParser/ElementGetter/Elements/NullElement.h \
    JSONParser/ElementGetter/Elements/NumberElement.h \
    JSONParser/ElementGetter/Elements/ObjectElement.h \
    JSONParser/ElementGetter/Elements/StringElement.h \
    JSONParser/JSONFile.h \
    JSONParser/JSONParser.h \
    JSONParser/ParseExceptions/ParseException.h \
    JSONParser/ParseResult.h \
    JSONParser/TokenGetter/TokenGetter.h \
    JSONParser/TokenGetter/TokenReaders.h \
    JSONParser/TokenGetter/TokenReaders/ArrayCloseTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/ArrayOpenTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/BaseTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/BooleanTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/ColonTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/CommaTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/CurlyCloseTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/CurlyOpenTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/NullTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/NumberTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/StringTokenReader.h \
    JSONParser/TokenGetter/TokenReaders/UnknownTokenReader.h \
    JSONParser/TokenGetter/Tokens.h \
    JSONParser/TokenGetter/Tokens/ArrayCloseToken.h \
    JSONParser/TokenGetter/Tokens/ArrayOpenToken.h \
    JSONParser/TokenGetter/Tokens/BaseToken.h \
    JSONParser/TokenGetter/Tokens/BooleanToken.h \
    JSONParser/TokenGetter/Tokens/ColonToken.h \
    JSONParser/TokenGetter/Tokens/CommaToken.h \
    JSONParser/TokenGetter/Tokens/CurlyCloseToken.h \
    JSONParser/TokenGetter/Tokens/CurlyOpenToken.h \
    JSONParser/TokenGetter/Tokens/NullToken.h \
    JSONParser/TokenGetter/Tokens/NumberToken.h \
    JSONParser/TokenGetter/Tokens/StringToken.h \
    JSONParser/TokenGetter/Tokens/UnknownToken.h \
    JSONReader/JSONReader.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
