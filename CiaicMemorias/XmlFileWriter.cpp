#include "XmlFileWriter.h"
#include <string>
#include <QtXml>
#include "OutputFileWriter.h"
#include <QString>
#include <QStringList>
using std::string;

string XmlFileWriter::getProjectName() const
{
    return projectName;
}

void XmlFileWriter::setProjectName(const string &value)
{
    projectName = value;
}
void XmlFileWriter::addTestingSet(QString value)
{
    testingSets.append(value);
}
void XmlFileWriter::addTrainingSet(QString value)
{
    trainingSets.append(value);
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


    //Attributes
    root.setAttribute("projectName",QString::fromStdString(projectName));
    output.setAttribute("outputFile",QString::fromStdString(outputFile));
    //Input testiing set and training sets.
    if (testingSets.size()>0){
        int i=0;
        QDomElement topTesting = document.createElement("Testing_Sets");
        foreach (QString testFile, testingSets) {
            QDomElement test  = document.createElement("Test_"+QString::number(i+1));
            test.setAttribute("File", testFile);
            i++;
            topTesting.appendChild(test);
        }
        input.appendChild(topTesting);
    }
    if (trainingSets.size()>0){
        int i=0;
        QDomElement topTraining = document.createElement("Training_Sets");

        foreach (QString trainingFile, trainingSets) {
            QDomElement training  = document.createElement("Train_"+QString::number(i+1));
            training.setAttribute("File", trainingFile);
            i++;
            topTraining.appendChild(training);
        }
        input.appendChild(topTraining);
    }

    // Creating basic structure
    root.appendChild(input);
    root.appendChild(output);

    document.appendChild(root);

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
