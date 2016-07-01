#ifndef MEMORIASASOCIATIVAS_H
#define MEMORIASASOCIATIVAS_H

#include <LearningAlgorithm.h>
#include "DataFormat.h"


class AssociativeMemories : public LearningAlgorithm {
protected:
    DataFormat data;
    int ** matrix;
    int ** outputVector;
    int cantMatrixRows;
    int cantColMatriz;
public:
    DataFormat getFormatoDeDatos() {
        return data;

    };
    void setFormatoDeDatos(DataFormat f ) {
        data = f;
    };
    AssociativeMemories(DataFormat d) {
        data = d;
        matrix = new int*[data.getNumFil()];
        for(int i = 0; i < data.getNumFil(); ++i) {
            matrix[i] = new int[data.getNumCol()];
        }

        cantMatrixRows = data.getNumFil();
        cantColMatriz = data.getNumCol();
    };
    ~AssociativeMemories() {
        for(int i = 0; i < data.getNumFil(); ++i) {
            delete [] matrix[i];
        }
        delete [] matrix;
    };
    int **getMatriz() {
        return matrix;
    };
    void setMatriz(int ** m) {
        matrix = m;
    };
    int ** getVectorSalida() {
        return outputVector;
    };
    void setVectorSalida(int ** v) {
        outputVector=v;
    };
};

#endif // MEMORIASASOCIATIVAS_H
