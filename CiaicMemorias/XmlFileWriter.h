#ifndef XMLFILEWRITER_H
#define XMLFILEWRITER_H

#include "OutputFileWriter.h"
#include <QStringList>
#include <string>

using std::string;
class XmlFileWriter : public OutputFileWriter
{
public:
    string projectName;
    string inputFile;
    string outputFile;
    QStringList testingSets;
    QStringList trainingSets;
    void write();
    string getProjectName() const;
    void setProjectName(const string &value);
    string getInputFile() const;
    void setInputFile(const string &value);
    string getOutputFile() const;
    void setOutputFile(const string &value);
    void addTestingSet(QString value);
    void addTrainingSet(QString value);
};

#endif // XMLFILEWRITER_H
