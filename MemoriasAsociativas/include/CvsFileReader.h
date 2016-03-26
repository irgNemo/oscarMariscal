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
    FormatoDeDatos datos;


    public:
        CvsFileReader(string direccion);
        virtual ~CvsFileReader();
        void read();
        //TODO pensar en renombrar formato de datos para la claridad
        FormatoDeDatos getFormatoDeDatos();
        void setFormatoDeDatos(FormatoDeDatos datos);

};

#endif // CVSFILEREADER_H
