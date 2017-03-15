#include "mainwindow.h"
#include <QApplication>
#include "LearnMatrix.h"
#include "DataFormat.h"
#include "Util.h"
#include "CsvFileReader.h"
#include "AlfaBetaMax.h"
#include <QDebug>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Util helper;
    DataFormat datos;

    int** ary = new int*[3];
    ary[0] =helper.getRandomBinaryArray(3);
    ary[1] =helper.getRandomBinaryArray(3);
    ary[2] =helper.getRandomBinaryArray(3);
    datos.setFundamentalSet(ary);
    datos.setNumCol(3);
    datos.setNumFil(3);
    LearnMatrix matriz(datos);
    AlfaBetaMax memoryMax(datos);
    matriz.printFundamentalSet();
    w.show();
    CsvFileReader hey("learnMatrixUno.txt");
    return a.exec();
}
