#include <iostream>
#include "AlgoritmoAprendizaje.h"
#include "MemoriasAsociativas.h"
#include "MemoriasAsociativasBinarias.h"
#include "LearnMatrix.h"
using namespace std;

int main()
{
    int rowCount=5;
    int colCount=5;
    int** ary = new int*[rowCount];
    for(int i = 0; i < rowCount; ++i){
        ary[i] = new int[colCount];
    }
    ary[0][0]=39;
    LearnMatrix lern;
    lern.setMatriz(ary);
    lern.imprimirMatriz();


    return 0;
}
