#include <iostream>
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


using namespace std;

int main()
{
//    Util::testLearnMatrix();
    Util::testAlphaBethaMax();

//    CsvFileWriter writer;
//    DataFormat data;
//    AlfaBetaMax alfaBetaObjetoEjemplo(data);
//    cout << endl << endl;
//    cout << "Giving a pattern to recognize" << endl;
//    int *patronDeSalida;
//    CsvFileReader patternsToRecognize("patternsToRecognize.txt");
//    patternsToRecognize.read();
//    int ** patterns = patternsToRecognize.getDataFormat().getFundamentalSet();
//    int colNumber = patternsToRecognize.getDataFormat().getNumCol();
//    int rowNumber = patternsToRecognize.getDataFormat().getNumFil();
//
//    for (int i = 0 ; i < rowNumber; i++){
//        patronDeSalida =lern.retrievalMethod(patterns[i],5);
//        for (int j =0 ; j <colNumber; j++)
//            cout << patterns[i][j] << ":";
//        cout << "->";
//        for (int j =0 ; j <lern.getFormatoDeDatos().getNumFil(); j++)
//            cout << patronDeSalida[j] << ":";
//        cout << "\n";
//    }
//
//    cout << "------------------------" << endl;
//    alfaBetaObjetoEjemplo.oneHot();
//    alfaBetaObjetoEjemplo.learningMethod();
//    alfaBetaObjetoEjemplo.printMatrix();
//
//    int* pattern =  alfaBetaObjetoEjemplo.retrievalMethod(data.getFundamentalSet()[0],3);
//    cout << endl << endl << endl;
//
//    cout << pattern[0] << ":"<< pattern[1] << ":" << pattern[2];
//
//
//    return 0;
}
