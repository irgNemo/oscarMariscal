#ifndef MEMORIASASOCIATIVAS_H
#define MEMORIASASOCIATIVAS_H

#include <AlgoritmoAprendizaje.h>


class MemoriasAsociativas : public AlgoritmoAprendizaje
{
    //TODO crear contructor para eliminar las variablse de matriz y vectorSalida para,
    protected:
        int ** matriz;
        int ** vectorSalida;
    public:
        MemoriasAsociativas();
        ~MemoriasAsociativas();
        int **getMatriz();
        void setMatriz(int ** m);
        int ** getVectorSalida();
        void setVectorSalida(int ** v);
};

#endif // MEMORIASASOCIATIVAS_H
