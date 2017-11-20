#include "ConfusionMatrix.h"
#include <sstream>
#include "qdebug.h"

using std::stringstream;

ConfusionMatrix::ConfusionMatrix(int sizeOfConfusionMatrix)
{
    size = sizeOfConfusionMatrix;
    confusionMatrix = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        confusionMatrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0 ;j < size; j++){
            confusionMatrix[i][j]=0;
        }
    }
}

int ConfusionMatrix::getCorrectlyClassifyFor(int numberOfClass)
{
    return confusionMatrix[numberOfClass][numberOfClass];
}

void ConfusionMatrix::addInstance(int classNumber, int classyfyAs)
{
    confusionMatrix[classNumber][classyfyAs]+=1;
}

std::__cxx11::string ConfusionMatrix::getStringRepresentation()
{

    stringstream data;
    for (int i = 0; i < size; i++){
        for (int j = 0 ;j < size; j++){
            data << confusionMatrix[i][j] ;
            if (j+1!=size){
                data << " : ";
            }
        }
        data << "\n";
    }
    return data.str();
}

int ConfusionMatrix::numberOfInstances()
{

}



