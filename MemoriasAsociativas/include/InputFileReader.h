#ifndef INPUTFILEREADER_H
#define INPUTFILEREADER_H

#include <InputReader.h>
#include <string>


class InputFileReader : public InputReader
{
    std::string direccion;
    public:
        InputFileReader();
        virtual ~InputFileReader();
};

#endif // INPUTFILEREADER_H
