#include "Util.h"

#include <cstdlib>
#include <ctime>
#include "LearnMatrix.h"
#include "AlfaBetaMax.h"
#include "DataFormat.h"
#include "CsvFileReader.h"
#include "CsvFileWriter.h"
#include <iostream>

using namespace std ;

int* Util::getRandomBinaryArray(int sizeOfArray) {
    int* arrayToReturn;
    arrayToReturn = new int[sizeOfArray];
    for (int i = 0 ; i < sizeOfArray; i++) {
        arrayToReturn[i]= std::rand()%2;
    }
    return arrayToReturn;
}

Util :: Util() {
    std::srand(std::time(0));
}

void Util::testLearnMatrix() {
    DataFormat data;
    CsvFileReader lector("learnMatrixUno.txt");
    lector.read();
    data = lector.getDataFormat();
    LearnMatrix lern(data);
    cout << "Printing the matrix before learning" << endl;
    lern.printMatrix();
    cout << "Printing the output vectors" << endl;
    lern.oneHot();
    lern.printOutputVectors();
    lern.learningMethod();
    cout << "Printing the fundamental set" << endl;
    lern.printFundamentalSet();
    cout << "Printing the matrix after learning" << endl;
    lern.printMatrix();
}

void Util::testAlphaBethaMax()
{
    DataFormat data;
    CsvFileReader lector("alfaBetaMax.txt");
    CsvFileReader patternsToRecognize("AlphaBetaMaxPatterns.txt");
    patternsToRecognize.read();
    lector.read();
    data = lector.getDataFormat();
    AlfaBetaMax alfa(data);
    cout << "Input" << endl;
    alfa.printFundamentalSet();
    cout << "Output" << endl;
    alfa.oneHot();
    alfa.printOutputVectors();

    cout << "Before learning" << endl;
    alfa.printMatrix();
    cout << "Matrix after learning" << endl;
    alfa.learningMethod();
    alfa.printMatrix();
    //
    cout << "Recognizing a few patterns" << endl;

    int ** patterns = patternsToRecognize.getDataFormat().getFundamentalSet();
    int *patronDeSalida;
    int colNumber = patternsToRecognize.getDataFormat().getNumCol();
    int rowNumber = patternsToRecognize.getDataFormat().getNumFil();
    for (int i = 0 ; i < rowNumber; i++) {
//        for (int j =0 ; j <colNumber; j++){
//            cout << "y"<<j<<":"<< patterns[i][j] << " ";
//        }
        patronDeSalida =alfa.retrievalMethod(patterns[i],3);
//        cout << "->";
//        for (int j =0 ; j <alfa.getFormatoDeDatos().getNumFil(); j++)
//            cout << patronDeSalida[j] << ":";
//        cout << "\n";
    }
}
