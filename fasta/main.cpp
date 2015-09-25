#include <iostream>
#include"Fasta.h"

using namespace std;

int main()
{
    Fasta archivoFasta("C:\\Users\\Administrador\\Dropbox\\Documentos\\Proyecto\\sequence.fasta");
    cout <<archivoFasta.getCabecera() << endl;
    cout << archivoFasta.getDatosDeSecuencia();
    return 0;
}
