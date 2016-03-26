#ifndef FORMATODEDATOS_H
#define FORMATODEDATOS_H
#include <string>


using std::string;
class FormatoDeDatos
{
    string cabecera;
    string nombreDeAtributos[];
    string nombreDeClases[];
    int ** conjuntoFundamental;

        int numFil;
        int numCol;
    public:
        //TODO Renombrar para que sea mas claro que se riefieren a el conjuntoFundamental
        int getNumCol();
        int getNumFil();
        void setNumCol(int c);
        void setNumFil(int f);
        FormatoDeDatos();
        virtual ~FormatoDeDatos();
        int ** getConjuntoFundamental();
        void setConjuntoFundamental(int ** c);

};

#endif // FORMATODEDATOS_H
