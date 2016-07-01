#include <iostream>
#include "LearningAlgorithm.h"
#include "AssociativeMemories.h"
#include "BinaryAssociativeMemories.h"
#include "LearnMatrix.h"
#include "DataFormat.h"
#include "InputFileReader.h"
#include "InputReader.h"
#include "CvsFileReader.h"
using namespace std;

int main()
{
    CvsFileReader lector("conjuntoFundamentalEjemploUno.txt");
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
    cout << "Giving a patter to recognize" << endl;
    int patronEjemplo[5];
    patronEjemplo[0]=1;
    patronEjemplo[1]=0;
    patronEjemplo[2]=0;
    patronEjemplo[3]=1;
    patronEjemplo[4]=1;
    int *patronDeSalida;
    patronDeSalida =lern.retrievalMethod(patronEjemplo,5);
    for (int i =0 ; i <lern.getFormatoDeDatos().getNumFil() ; i++) //Cookies <3
        cout << patronDeSalida[i] << ":";
    lern.learningMethod();
    return 0;
}
