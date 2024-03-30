 #include "JSONReader.h"


JSONReader::JSONReader(std::string filename) : _filename (filename)
{
    this->openFile();
}

bool JSONReader::isGood()
{
    return this->_file.good();
}

bool JSONReader::isOpened()
{
    return this->_file.is_open();
}

std::string JSONReader::getFilename()
{
    return this->_filename;
}

std::string JSONReader::readAll()
{
    std::string temp;
    std::string result;

    while (this->isGood() && std::getline(this->_file, temp))
        result += (temp + "\n");

    return result;
}

void JSONReader::openFile()
{
    if (!this->isOpened())
        this->_file.open(this->_filename);
}

void JSONReader::closeFile()
{
    if (this->isOpened())
        this->_file.close();
}

JSONReader::~JSONReader()
{
    this->closeFile();
}
