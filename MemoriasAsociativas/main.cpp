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
    CvsFileReader lector;

    FormatoDeDatos formato;
    int **matriz = new int*[3];
    for(int i = 0; i < 5; ++i){
        matriz[i] = new int[5];
    }

    matriz[0][0]=1;
    matriz[0][1]=0;
    matriz[0][2]=0;
    matriz[0][3]=1;
    matriz[0][4]=1;

    matriz[1][0]=0;
    matriz[1][1]=1;
    matriz[1][2]=1;
    matriz[1][3]=0;
    matriz[1][4]=1;

    matriz[2][0]=1;
    matriz[2][1]=1;
    matriz[2][2]=0;
    matriz[2][3]=0;
    matriz[2][4]=0;


    formato.setConjuntoFundamental(matriz);
    formato.setNumCol(5);
    formato.setNumFil(3);

    LearnMatrix lern(formato);
    cout << "Imprimiendo la matriz antes de aprender" << endl;
    lern.imprimirMatriz();
    cout << "Imprimiendo los vectores de salida" << endl;
    lern.oneHot();
    lern.imprimirVectorSalida();
    lern.metodoAprendizaje();
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

    lern.metodoRecuperacion(patronEjemplo,5);
//    lern.metodoAprendizaje();
    return 0;
}
