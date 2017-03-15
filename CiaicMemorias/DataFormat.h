#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include <string>

using std::string ;

class DataFormat
{
    string header;
    string atributeNames[];
    string classesNames[];
    int ** fundamentalSet;

    int numFil;
    int numCol;

    public:
        //TODO Renombrar para que sea mas claro que se riefieren a el conjuntoFundamental
        int getNumCol();
        int getNumFil();
        void setNumCol(int c);
        void setNumFil(int f);
        DataFormat();
        virtual ~DataFormat();
        int ** getFundamentalSet();
        void setFundamentalSet(int ** c);
        void createRandomFundamentalSet(int rows, int columns);
};

#endif // DATAFORMAT_H
