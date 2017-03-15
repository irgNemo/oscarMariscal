#ifndef CVSFILEREADER_H
#define CVSFILEREADER_H

#include "DataFormat.h"
#include <InputFileReader.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::string;


class CsvFileReader : public InputFileReader
{
    string path;
    DataFormat data;
    public:
        CsvFileReader(string direccion);
        virtual ~CsvFileReader();
        void read();
        void read(string direccion);
        DataFormat getDataFormat();
        void setDataFormat(DataFormat datos);

};

#endif // CVSFILEREADER_H
