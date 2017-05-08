#ifndef CSVFILEREADER_H
#define CSVFILEREADER_H
#include "InputFileReader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DataFormat.h"
#include <vector>
using std::string;

class CsvFileReader : public InputFileReader
{
    string path;
    DataFormat data;
    std::vector<string>headers;
    public:
        CsvFileReader(string direccion);
        virtual ~CsvFileReader();
        void read();
        void read(string direccion);
        DataFormat getDataFormat();
        void setDataFormat(DataFormat datos);

        std::vector<string> getHeaders() const;
};

#endif // CSVFILEREADER_H
