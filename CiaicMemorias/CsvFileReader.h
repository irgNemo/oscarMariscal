#ifndef CSVFILEREADER_H
#define CSVFILEREADER_H
#include "InputFileReader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DataFormat.h"

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

#endif // CSVFILEREADER_H
