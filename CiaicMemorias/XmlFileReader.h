#ifndef XMLFILEREADER_H
#define XMLFILEREADER_H
#include "InputFileReader.h"
#include "DataFormat.h"
#include <QString>
#include <QStringList>


using std::string;


class XmlFileReader : InputFileReader
{
private:
    QString projectName;
    QString inputFile;
    QString outputFile;
    QStringList testingSets;
    QStringList trainingSets;
public:
    XmlFileReader(string f);
    void read();
    void read(string direccion);
    DataFormat getDataFormat();
    void setDataFormat(DataFormat datos);

    QString getProjectName() const;
    void setProjectName(const QString &value);
    QString getInputFile() const;
    void setInputFile(const QString &value);
    QString getOutputFile() const;
    void setOutputFile(const QString &value);
    QStringList getTestingSets() const;
    QStringList getTrainingSets() const;
};

#endif // XMLFILEREADER_H
