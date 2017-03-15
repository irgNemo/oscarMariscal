#include "OutputFileWriter.h"
OutputFileWriter::OutputFileWriter()
{
    //ctor
}

string OutputFileWriter::getPath()
{
    return path;
}

void OutputFileWriter::setPath(string p)
{
    path = p;
}

string OutputFileWriter::getFileName()
{
    return fileName;
}

void OutputFileWriter::setFileName(string f)
{
    fileName = f;
}

DataFormat OutputFileWriter::getDataFormat()
{
    return data;
}

void OutputFileWriter::setDataFormat(DataFormat d)
{
    data = d;
}
