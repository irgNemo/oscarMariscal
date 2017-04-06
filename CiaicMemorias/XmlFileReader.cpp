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
            inputFile = son.attribute("inputFile");
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
