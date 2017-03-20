#ifndef XMLFILEREADER_H
#define XMLFILEREADER_H
#include "InputFileReader.h"
#include "DataFormat.h"

using std::string;


class XmlFileReader : InputFileReader
{
public:
    XmlFileReader();
    void read();
    void read(string direccion);
    DataFormat getDataFormat();
    void setDataFormat(DataFormat datos);
};

#endif // XMLFILEREADER_H
