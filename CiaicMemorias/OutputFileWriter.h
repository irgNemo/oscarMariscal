#ifndef OUTPUTFILEWRITER_H
#define OUTPUTFILEWRITER_H

#include "DataFormat.h"
#include "OutputWriter.h"

class OutputFileWriter : OutputWriter
{
protected:
    DataFormat data;
    string path;
    string fileName;
public:
    virtual void write()=0;
    OutputFileWriter();
    DataFormat getDataFormat();
    void setDataFormat(DataFormat d);
    string getPath();
    void setPath(string p);
    string getFileName();
    void setFileName(string f);
};

#endif // OUTPUTFILEWRITER_H
