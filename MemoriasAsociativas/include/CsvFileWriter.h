#ifndef CSVFILEWRITER_H
#define CSVFILEWRITER_H

#include <OutputFileWriter.h>


class CsvFileWriter : public OutputFileWriter
{
    public:
    CsvFileWriter();
    void write();
};

#endif // CSVFILEWRITER_H
