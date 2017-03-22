#ifndef XMLFILEWRITER_H
#define XMLFILEWRITER_H

#include "OutputFileWriter.h"
#include <string>

using std::string;
class XmlFileWriter : OutputFileWriter
{
public:
    void write();
};

#endif // XMLFILEWRITER_H
