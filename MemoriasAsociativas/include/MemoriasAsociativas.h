#ifndef MEMORIASASOCIATIVAS_H
#define MEMORIASASOCIATIVAS_H

#include <AlgoritmoAprendizaje.h>
#include "FormatoDeDatos.h"


class MemoriasAsociativas : public AlgoritmoAprendizaje
{
    protected:
        FormatoDeDatos datos;
        int ** matriz;
        int ** vectoresSalida;
        int filMatriz;
        int colMatriz;
    public:
        FormatoDeDatos getFormatoDeDatos();
        void setFormatoDeDatos(FormatoDeDatos f );
        MemoriasAsociativas(FormatoDeDatos d);
        ~MemoriasAsociativas();
        int **getMatriz();
        void setMatriz(int ** m);
        int ** getVectorSalida();
        void setVectorSalida(int ** v);
};

#endif // MEMORIASASOCIATIVAS_H
