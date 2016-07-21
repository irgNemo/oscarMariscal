#include <iostream>
#include "LearningAlgorithm.h"
#include "AssociativeMemories.h"
#include "BinaryAssociativeMemories.h"
#include "LearnMatrix.h"
#include "DataFormat.h"
#include "InputFileReader.h"
#include "InputReader.h"
#include "CvsFileReader.h"

#include <vector>
using namespace std;

int main()
{
    CvsFileReader lector("conjuntoFundamentalEjemploUno.txt");
    lector.read();
    LearnMatrix lern(lector.getDataFormat());
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
    cout << endl << endl;
    cout << "Giving a pattern to recognize" << endl;
    int *patronDeSalida;
    CvsFileReader patternsToRecognize("patternsToRecognize.txt");
    patternsToRecognize.read();
    int ** patterns = patternsToRecognize.getDataFormat().getFundamentalSet();
    int colNumber = patternsToRecognize.getDataFormat().getNumCol();
    int rowNumber = patternsToRecognize.getDataFormat().getNumFil();

    for (int i = 0 ; i < rowNumber; i++){
        patronDeSalida =lern.retrievalMethod(patterns[i],5);
        for (int j =0 ; j <colNumber; j++)
            cout << patterns[i][j] << ":";
        cout << "->";
        for (int j =0 ; j <lern.getFormatoDeDatos().getNumFil(); j++)
            cout << patronDeSalida[j] << ":";
        cout << "\n";
    }

    return 0;
}
