#ifndef BINARYASSOCIATIVEMEMORIES_H
#define BINARYASSOCIATIVEMEMORIES_H

#include "AssociativeMemories.h"


class BinaryAssociativeMemories : public AssociativeMemories
{
protected:
    int ** matrix;
    int ** outputVector;
public:

    BinaryAssociativeMemories(DataFormat d);

    ~BinaryAssociativeMemories();

    int **getMatriz();

    void setMatriz(int ** m);
    int **& getVectorSalida();
    void setVectorSalida(int ** v);
};

#endif // BINARYASSOCIATIVEMEMORIES_H
