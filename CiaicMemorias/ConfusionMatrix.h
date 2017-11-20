#ifndef CONFUSIONMATRIX_H
#define CONFUSIONMATRIX_H
#include <string>


using std::string;

class ConfusionMatrix
{
    int **confusionMatrix;
    int size;
public:
    ConfusionMatrix(int sizeOfConfusionMatrix);
    int getCorrectlyClassifyFor(int numberOfClass);
    void addInstance(int classNumber, int classyfyAs);
    string getStringRepresentation();
    int numberOfInstances();
};

#endif // CONFUSIONMATRIX_H
