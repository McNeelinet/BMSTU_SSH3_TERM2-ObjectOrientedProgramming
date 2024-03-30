 #include "JSONFile.h"


JSONFile::JSONFile(std::string filename) : _filename (filename)
{
    this->openFile();

    this->_currentPosition = {.line = 1, .column = 1,
                              .pos = this->_file.tellg()};
    this->_previousPosition = _currentPosition;
}

void JSONFile::openFile()
{
    if (!this->isOpened())
        this->_file.open(this->_filename);
}

void JSONFile::closeFile()
{
    if (this->isOpened())
        this->_file.close();
}

bool JSONFile::isGood()
{
    return this->_file.good();
}

bool JSONFile::isOpened()
{
    return this->_file.is_open();
}

bool JSONFile::isEnd()
{
    return this->_file.eof();
}

std::string JSONFile::getFilename()
{
    return this->_filename;
}

position JSONFile::getCurrentPosition()
{
    return this->_currentPosition;
}

char JSONFile::readChar()
{
    char c;

    this->_previousPosition = this->_currentPosition;
    this->_file.get(c);
    if (c == '\n') {
        this->_currentPosition.line += 1;
        this->_currentPosition.column = 1;
    }
    else
        this->_currentPosition.column += 1;
    this->_currentPosition.pos = this->_file.tellg();

    return c;
}

char JSONFile::readCharSkipSpaces()
{
    char c;

    do {
        c = this->readChar();
        if (this->isEnd())
            throw std::ios_base::failure("Unexpected out of data");
    }
    while (std::isspace(c));

    return c;
}

void JSONFile::rollBack()
{
    if (this->_currentPosition.pos != this->_previousPosition.pos) {
        this->_file.seekg(this->_previousPosition.pos);
        this->_currentPosition = this->_previousPosition;
    }
}

JSONFile::~JSONFile()
{
    this->closeFile();
}
