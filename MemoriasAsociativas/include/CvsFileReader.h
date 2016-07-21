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

//TODO el nombre de la clase esta mal, deberia ser csv no cvs

class CvsFileReader : public InputFileReader
{
    string path;
    DataFormat data;
    public:
        CvsFileReader(string direccion);
        virtual ~CvsFileReader();
        void read();
        void read(string direccion);
        DataFormat getDataFormat();
        void setDataFormat(DataFormat datos);

};

#endif // CVSFILEREADER_H
