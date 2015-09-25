#include "Fasta.h"

Fasta::Fasta(string direccionArchivo)
{
    string linea;
    cabecera="";
    datosDeSecuencia="";
    archivo.open(direccionArchivo);
    if (archivo.is_open()){
        getline(archivo,linea);
        cabecera=linea;
        while(getline(archivo,linea)){
            datosDeSecuencia+=linea;
        }
    }
    else{
        //Disparar error
    }
}

string Fasta::getDatosDeSecuencia(){
    return datosDeSecuencia;
}

string Fasta::getCabecera(){
    return cabecera;
}
