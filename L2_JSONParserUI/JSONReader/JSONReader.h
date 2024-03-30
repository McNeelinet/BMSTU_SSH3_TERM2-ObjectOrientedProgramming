#ifndef JSONREADER_H
#define JSONREADER_H

#include <string>
#include <fstream>


class JSONReader
{
public:
    JSONReader(std::string filename);

    bool isGood();
    bool isOpened();

    std::string getFilename();

    std::string readAll();

    ~JSONReader();

private:
    void openFile();
    void closeFile();

    std::string _filename;
    std::fstream _file;
};

#endif // JSONREADER_H
