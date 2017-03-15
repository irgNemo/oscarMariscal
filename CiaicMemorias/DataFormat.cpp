#include "DataFormat.h"
#include "Util.h"

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

void DataFormat::createRandomFundamentalSet(int rows, int columns){
    setNumCol(columns);
    setNumFil(rows);
    Util utilHelper;
    int** ary = new int*[rows];
    for(int i = 0; i < rows; ++i)
        ary[i] =utilHelper.getRandomBinaryArray(columns);
    fundamentalSet=ary;
}
