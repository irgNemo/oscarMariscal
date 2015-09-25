#include "Lernmatrix.h"

Lernmatrix::Lernmatrix(int x , int y){
    int** conjuntoFundamental = new int* [x];
    for (int i =0 ; i< x; i++){
        conjuntoFundamental[i] =new int [y];
    }
}

int Lernmatrix:: reglaAprendizaje(int x, int y){
    int resultado=0;
    if (x==1 && y ==1){
        resultado =EPSILON;
    }
    else if (x==0 && y == 1) {
        resultado = -EPSILON;
    }
    else{
        resultado = 0;
    }
    return resultado;
}

int Lernmatrix::reglaRecuperacion(){

}
