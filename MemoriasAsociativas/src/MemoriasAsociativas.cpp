#include "MemoriasAsociativas.h"

MemoriasAsociativas::MemoriasAsociativas()
{
    //ctor
}

MemoriasAsociativas::~MemoriasAsociativas(){
//    for(int i = 0; i < sizeY; ++i) {
//        delete [] ary[i];
//    }
//    delete [] ary;
}
int ** MemoriasAsociativas:: getMatriz(){
    return matriz;
}

void MemoriasAsociativas:: setMatriz(int ** m){
    matriz = m;
}

int ** MemoriasAsociativas:: getVectorSalida(){
    return vectorSalida;
}

void MemoriasAsociativas::setVectorSalida(int ** v){
    vectorSalida=v;
}
