#include "XmlFileReader.h"
#include <QtXml>


QString XmlFileReader::getProjectName() const
{
    return projectName;
}

void XmlFileReader::setProjectName(const QString &value)
{
    projectName = value;
}

QString XmlFileReader::getInputFile() const
{
    return inputFile;
}

void XmlFileReader::setInputFile(const QString &value)
{
    inputFile = value;
}

QString XmlFileReader::getOutputFile() const
{
    return outputFile;
}

void XmlFileReader::setOutputFile(const QString &value)
{
    outputFile = value;
}

QStringList XmlFileReader::getTestingSets() const
{
    return testingSets;
}

QStringList XmlFileReader::getTrainingSets() const
{
    return trainingSets;
}

XmlFileReader::XmlFileReader(string f): InputFileReader(f)
{

}

void XmlFileReader::read()
{
    read(filePath);

}

void XmlFileReader::read(std::__cxx11::string direccion)
{
    QDomDocument doc;
    //QFile file( "projectOne.xml");
    QFile file( QString::fromStdString(direccion));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Eror al abrir" ;
    }
    else{
        if (!doc.setContent(&file)){
            qDebug() << "Error al leer el archivo";
        }
        file.close();
    }
    QDomElement root =doc.firstChildElement();
    projectName = root.attribute("projectName");
    QDomElement son = root.firstChildElement();
    while (!son.isNull()){
        if (son.tagName().compare("input",Qt::CaseInsensitive) == 0 ){

            QDomElement first=son.firstChildElement();
            QDomElement second=first.nextSiblingElement();
            QDomElement childOfTesting;
            QDomElement childOfTraining;

            qDebug() << "son.tagName()";
            qDebug() << son.tagName();
            if (first.tagName().compare("Testing_Sets",Qt::CaseInsensitive) == 0){
                childOfTesting =first.firstChildElement() ;

            }
            else if (first.tagName().compare("Training_Sets",Qt::CaseInsensitive) == 0){
                childOfTraining = first.firstChildElement();
            }
            if (second.tagName().compare("Testing_Sets",Qt::CaseInsensitive) == 0){
                childOfTesting =second.firstChildElement();
            }
            else if (second.tagName().compare("Training_Sets",Qt::CaseInsensitive) == 0){
                childOfTraining = second.firstChildElement();
            }
            qDebug() << childOfTesting.isNull();
            while(!childOfTesting.isNull()){
                QString testingFile = childOfTesting.attribute("File");
                testingSets.append(testingFile);
                childOfTesting=childOfTesting.nextSiblingElement();
            }
            while(!childOfTraining.isNull()){
                QString trainingFile = childOfTraining.attribute("File");
                trainingSets.append(trainingFile);
                childOfTraining=childOfTesting.nextSiblingElement();
            }
        }
        else if (son.tagName().compare("output",Qt::CaseInsensitive) == 0 ){
            outputFile = son.attribute("outputFile");
        }
        son = son.nextSiblingElement();
    }

}

DataFormat XmlFileReader::getDataFormat()
{

}

void XmlFileReader::setDataFormat(DataFormat datos)
{

}
