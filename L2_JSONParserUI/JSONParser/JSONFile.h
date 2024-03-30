#ifndef JSONFILE_H
#define JSONFILE_H

#include <string>
#include <ios>
#include <fstream>
#include <memory>

struct position
{
    size_t line;
    size_t column;
    long pos;
};


class JSONFile
{
public:    
    JSONFile(std::string filename);

    bool isGood();
    bool isOpened();
    bool isEnd();

    std::string getFilename();
    position getCurrentPosition();

    char readChar();
    char readCharSkipSpaces();
    void rollBack();

    ~JSONFile();

private:
    JSONFile(const JSONFile&) = delete;
    JSONFile& operator= (const JSONFile&) = delete;
    void openFile();
    void closeFile();

    std::string _filename;
    std::fstream _file;
    position _previousPosition;
    position _currentPosition;
};

#endif // JSONFILE_H
