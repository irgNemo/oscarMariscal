#include "CvsFileReader.h"

using namespace std;

//TODO este es el lugar adecuado para este metodo?
inline int toInt(std::string s) {
    int v;
    std::istringstream sin(s);
    sin>>v;
    return v;
}
//TODO mover lo necesario al metodo de read. o quitar el metodo read para que todo se haga en el contructor
CvsFileReader::CvsFileReader(string direccion):InputFileReader(direccion) {
    ifstream file( direccion.c_str() );
    vector<vector<std::string> >   matrix;
    vector<string>   row;
    string line;
    string cell;

    while( file ){
        getline(file,line);
        stringstream lineStream(line);
        row.clear();
        while(getline( lineStream, cell, ',' ) )
            row.push_back( cell );
        if(!row.empty() )
            matrix.push_back( row );
    }
    //Al parecer lee la ultima linea dos veces así que
    matrix.pop_back();
    int** matriz = new int*[matrix.size()];
    for(int i = 0; i <int(matrix.size()) ; ++i){
        matriz[i] = new int[matrix[i].size()];
    }
    for( int i=0; i<int(matrix.size()); i++ ){
        for( int j=0; j<int(matrix[i].size()); j++ )
            matriz[i][j]=toInt(matrix[i][j]);
    }
    datos.setConjuntoFundamental(matriz);
    std::cout << matrix.size();
    datos.setNumFil(matrix.size());
    datos.setNumCol(matrix[0].size());
}

CvsFileReader::~CvsFileReader() {
    //dtor
}

FormatoDeDatos CvsFileReader::getFormatoDeDatos(){
    return datos;

}

void CvsFileReader::setFormatoDeDatos(FormatoDeDatos datos){
    this->datos = datos;
}


void CvsFileReader::read() {
    //dtor
}
