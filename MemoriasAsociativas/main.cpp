#include <iostream>
#include "AlgoritmoAprendizaje.h"
#include "MemoriasAsociativas.h"
#include "MemoriasAsociativasBinarias.h"
#include "LearnMatrix.h"
#include "FormatoDeDatos.h"
#include "InputFileReader.h"
#include "InputReader.h"
#include "CvsFileReader.h"
using namespace std;

int main()
{
    CvsFileReader lector("conjuntoFundamentalEjemploUno.txt");
    LearnMatrix lern(lector.getFormatoDeDatos());
    cout << "Imprimiendo la matriz antes de aprender" << endl;
    lern.imprimirMatriz();
    cout << "Imprimiendo los vectores de salida" << endl;
    lern.oneHot();
    lern.imprimirVectorSalida();
    lern.learningMethod();
    cout << "Imprimiendo el conjunto fundamental" << endl;
    lern.imprimirConjuntoFunamental();
    cout << "Imprimiendo la matriz despues de aprender" << endl;
    lern.imprimirMatriz();
    cout << endl << endl;
    cout << "Dandole un patron a reconocer" << endl;
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
