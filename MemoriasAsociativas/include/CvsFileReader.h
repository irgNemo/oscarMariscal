#ifndef CVSFILEREADER_H
#define CVSFILEREADER_H

#include "FormatoDeDatos.h"
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
    DataFormat data;
    public:
        CvsFileReader(string direccion);
        virtual ~CvsFileReader();
        void read();
        DataFormat getFormatoDeDatos();
        void setFormatoDeDatos(DataFormat datos);

};

#endif // CVSFILEREADER_H
