#include "FormatoDeDatos.h"

FormatoDeDatos::FormatoDeDatos()
{
    //ctor
}
int FormatoDeDatos::getNumCol(){
    return numCol;
}

int FormatoDeDatos::getNumFil(){
    return numFil;
}

void FormatoDeDatos::setNumCol(int c){
    numCol = c;
}

void FormatoDeDatos::setNumFil(int f){
    numFil=f;
}

FormatoDeDatos::~FormatoDeDatos()
{
    //dtor
}
int** FormatoDeDatos::getConjuntoFundamental(){
    return conjuntoFundamental;
}

void FormatoDeDatos::setConjuntoFundamental(int** c){
    conjuntoFundamental = c;
}
