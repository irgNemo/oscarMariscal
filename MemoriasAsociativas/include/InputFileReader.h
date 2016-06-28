#ifndef INPUTFILEREADER_H
#define INPUTFILEREADER_H

#include <InputReader.h>
#include <string>
#include <fstream>

using std::string;

class InputFileReader : public InputReader
{
    protected:
    std::string filePath;
    std::ifstream archive;
    public:
        InputFileReader(string filePath);
};

#endif // INPUTFILEREADER_H
