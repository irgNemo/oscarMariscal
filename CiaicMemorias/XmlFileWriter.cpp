#include "XmlFileWriter.h"
#include <string>
#include <QtXml>
#include "OutputFileWriter.h"
using std::string;

string XmlFileWriter::getProjectName() const
{
    return projectName;
}

void XmlFileWriter::setProjectName(const string &value)
{
    projectName = value;
}

string XmlFileWriter::getInputFile() const
{
    return inputFile;
}

void XmlFileWriter::setInputFile(const string &value)
{
    inputFile = value;
}

string XmlFileWriter::getOutputFile() const
{
    return outputFile;
}

void XmlFileWriter::setOutputFile(const string &value)
{
    outputFile = value;
}

void XmlFileWriter::write()
{
    // Create a document to write XML
    QDomDocument document;

    QDomElement root   = document.createElement("Project");
    QDomElement input  = document.createElement("Input");
    QDomElement output = document.createElement("Output");
    QDomElement testingSets = document.createElement("TestingSets");

    //Attributes
    root.setAttribute("projectName",QString::fromStdString(projectName));
    input.setAttribute("inputFile",QString::fromStdString(inputFile));
    output.setAttribute("outputFile",QString::fromStdString(outputFile));

    // Creating basic structure
    root.appendChild(input);
    root.appendChild(output);
    root.appendChild(testingSets);
    document.appendChild(root);

    //Testing set
    // Writing to a file
    QFile file(QString::fromStdString(fileName));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open the file for writing failed";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Writing is done";
    }

}
