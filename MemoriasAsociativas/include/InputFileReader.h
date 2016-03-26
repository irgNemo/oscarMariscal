#ifndef INPUTFILEREADER_H
#define INPUTFILEREADER_H

#include <InputReader.h>
#include <string>
#include <fstream>

using std::string;

class InputFileReader : public InputReader
{
    protected:
    std::string direccion;
    std::ifstream archivo;
    public:
        InputFileReader(string direccion);
};

#endif // INPUTFILEREADER_H
