#ifndef XMLFILEWRITER_H
#define XMLFILEWRITER_H

#include "OutputFileWriter.h"
#include <string>

using std::string;
class XmlFileWriter : OutputFileWriter
{
public:
    string projectName;
    string inputFile;
    string outputFile;
    void write();
    string getProjectName() const;
    void setProjectName(const string &value);
    string getInputFile() const;
    void setInputFile(const string &value);
    string getOutputFile() const;
    void setOutputFile(const string &value);
};

#endif // XMLFILEWRITER_H
