#include "FormatoDeDatos.h"

DataFormat::DataFormat()
{
    //ctor
}
int DataFormat::getNumCol(){
    return numCol;
}

int DataFormat::getNumFil(){
    return numFil;
}

void DataFormat::setNumCol(int c){
    numCol = c;
}

void DataFormat::setNumFil(int f){
    numFil=f;
}

DataFormat::~DataFormat()
{
    //dtor
}
int** DataFormat::getFundamentalSet(){
    return fundamentalSet;
}

void DataFormat::setFundamentalSet(int** c){
    fundamentalSet = c;
}
