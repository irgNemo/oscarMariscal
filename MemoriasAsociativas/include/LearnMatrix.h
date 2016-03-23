#ifndef LEARNMATRIX_H
#define LEARNMATRIX_H

#include <MemoriasAsociativasBinarias.h>


class LearnMatrix : public MemoriasAsociativasBinarias
{
    public:
        LearnMatrix();
        void metodoAprendizaje();
        void imprimirMatriz();
        int * metodoRecuperacion();
        ~LearnMatrix();
};

#endif // LEARNMATRIX_H
