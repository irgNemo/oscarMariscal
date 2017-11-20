#ifndef CSVFILEWRITER_H
#define CSVFILEWRITER_H

#include "OutputFileWriter.h"
#include <vector>


class CsvFileWriter : public OutputFileWriter
{
    std::vector<string>headers;
public:
    CsvFileWriter();
    void write();
    void setHeaders(std::vector<string>headers);
};

#endif // CSVFILEWRITER_H
