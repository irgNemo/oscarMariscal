#ifndef FASTA_H
#define FASTA_H
#include <string>
#include <fstream>

using namespace std;

class Fasta
{
    private:
        string cabecera;
        string datosDeSecuencia;
        ifstream archivo;
    public:
        Fasta(string direccionArchivo);
        string getCabecera();
        string getDatosDeSecuencia();
};

#endif // FASTA_H
