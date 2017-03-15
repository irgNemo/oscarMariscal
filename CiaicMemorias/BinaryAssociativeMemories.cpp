#include "BinaryAssociativeMemories.h"
#include "AssociativeMemories.h"

BinaryAssociativeMemories::BinaryAssociativeMemories(DataFormat d):AssociativeMemories(d)
{
    data = d;
    matrix = new int*[data.getNumFil()];
    for(int i = 0; i < data.getNumFil(); ++i)
    {
        matrix[i] = new int[data.getNumCol()];
    }
    cantMatrixRows = data.getNumFil();
    cantColMatriz = data.getNumCol();
}

BinaryAssociativeMemories::~BinaryAssociativeMemories()
{
    for(int i = 0; i < data.getNumFil(); ++i)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

int **BinaryAssociativeMemories::getMatriz()
{
    return matrix;
}

void BinaryAssociativeMemories::setMatriz(int **m)
{
    matrix = m;
}

int **&BinaryAssociativeMemories::getVectorSalida()
{
    return outputVector;
}

void BinaryAssociativeMemories::setVectorSalida(int **v)
{
    outputVector=v;
}
