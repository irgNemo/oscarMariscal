#ifndef MEMORIASASOCIATIVAS_H
#define MEMORIASASOCIATIVAS_H

#include <LearningAlgorithm.h>
#include "DataFormat.h"


class AssociativeMemories : public LearningAlgorithm {
protected:
    DataFormat data;

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

    };
    ~AssociativeMemories() {

    };
};

#endif // MEMORIASASOCIATIVAS_H
