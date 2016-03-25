#ifndef LEARNMATRIX_H
#define LEARNMATRIX_H
#define EPSILON 1

#include <MemoriasAsociativasBinarias.h>


class LearnMatrix : public MemoriasAsociativasBinarias
{
    public:
        LearnMatrix(FormatoDeDatos d);
        ~LearnMatrix();
        void metodoAprendizaje();
        int * metodoRecuperacion(int *patron,int n);
        void oneHot();
        //Metodo de prueba
        void imprimirMatriz();
        void imprimirVectorSalida();
        void imprimirConjuntoFunamental();
};

#endif // LEARNMATRIX_H
