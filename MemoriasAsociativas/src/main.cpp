#include "mainwindow.h"
#include "LearningAlgorithm.h"
#include "AssociativeMemories.h"
#include "BinaryAssociativeMemories.h"
#include "LearnMatrix.h"
#include "DataFormat.h"
#include "InputFileReader.h"
#include "InputReader.h"
#include "CsvFileReader.h"
#include "Util.h"
#include "CsvFileWriter.h"
#include "AlfaBeta.h"
#include "AlfaBetaMax.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Util::testLearnMatrix();
    w.show();

    DataFormat data;
    CsvFileReader lector("learnMatrixUno.txt");
    lector.read();
    data = lector.getDataFormat();
    LearnMatrix lern(data);
    //cout << "Printing the matrix before learning" << endl;
    lern.printMatrix();
    //cout << "Printing the output vectors" << endl;
    lern.oneHot();
    //lern.printOutputVectors();
    lern.learningMethod();
    //cout << "Printing the fundamental set" << endl;
    lern.printFundamentalSet();
    //cout << "Printing the matrix after learning" << endl;
   // lern.printMatrix();

    return a.exec();
}
