#ifndef LECTORFASTA_H
#define LECTORFASTA_H
#include "Fasta.h"



class LectorFasta
{
    private:
        string cabecera;
        string datosDeSecuencia;
        ifstream archivo;
    public:
        LectorFasta(string direccionArchivo);
        string getCabecera();

        string getDatosDeSecuencia();
};

#endif // LECTORFASTA_H
