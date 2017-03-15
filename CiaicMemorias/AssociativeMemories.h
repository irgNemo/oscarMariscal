#ifndef ASSOCIATIVEMEMORIES_H
#define ASSOCIATIVEMEMORIES_H
#include "LearningAlgorithm.h"
#include "DataFormat.h"


class AssociativeMemories : public LearningAlgorithm
{
protected:
    DataFormat data;
    int cantMatrixRows;
    int cantColMatriz;
public:
    DataFormat getFormatoDeDatos();
    void setFormatoDeDatos(DataFormat f );
    AssociativeMemories(DataFormat d);
    ~AssociativeMemories();
};

#endif // ASSOCIATIVEMEMORIES_H
