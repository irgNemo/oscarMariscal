#include "LearnMatrix.h"
#include <iostream>

LearnMatrix::LearnMatrix()
{
    //ctor
}

void LearnMatrix:: metodoAprendizaje(){
}

int * LearnMatrix:: metodoRecuperacion(){
}

LearnMatrix:: ~ LearnMatrix(){
}

void LearnMatrix::imprimirMatriz(){
    for (int i = 0; i < 5 ;i++){
        for (int j = 0 ; j < 5 ; j++){
            std::cout << matriz[i][j] << ":" ;
        }
        std::cout << std::endl;
    }
}
