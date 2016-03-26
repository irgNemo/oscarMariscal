#include "MemoriasAsociativas.h"
#include <iostream>

/** \brief La matriz se pone en 0
 *
 * \param Recibe un FormatoDeDatos para el conjunto fundamental
 * \return
 *
 */

MemoriasAsociativas::MemoriasAsociativas(FormatoDeDatos d)
{
    datos = d;
    matriz = new int*[datos.getNumFil()];
    for(int i = 0; i < datos.getNumFil(); ++i){
        matriz[i] = new int[datos.getNumCol()];
    }

    filMatriz = datos.getNumFil();
    colMatriz = datos.getNumCol();
}

MemoriasAsociativas::~MemoriasAsociativas(){
    for(int i = 0; i < datos.getNumFil(); ++i) {
        delete [] matriz[i];
    }
    delete [] matriz;
}
int ** MemoriasAsociativas:: getMatriz(){
    return matriz;
}

void MemoriasAsociativas:: setMatriz(int ** m){
    matriz = m;
}

int ** MemoriasAsociativas:: getVectorSalida(){
    return vectoresSalida;
}

void MemoriasAsociativas::setVectorSalida(int ** v){
    vectoresSalida=v;
}

FormatoDeDatos MemoriasAsociativas::getFormatoDeDatos()
{
    return datos;
}

void MemoriasAsociativas::setFormatoDeDatos(FormatoDeDatos f)
{
    datos = f;
}

