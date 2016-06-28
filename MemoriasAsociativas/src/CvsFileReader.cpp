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
    //Reads the last line twice, so i do pop_back() to fix it, but it's a patch
    matrix.pop_back();
    int** matriz = new int*[matrix.size()];
    for(int i = 0; i <int(matrix.size()) ; ++i){
        matriz[i] = new int[matrix[i].size()];
    }
    for( int i=0; i<int(matrix.size()); i++ ){
        for( int j=0; j<int(matrix[i].size()); j++)
            matriz[i][j]=toInt(matrix[i][j]);
    }
    data.setFundamentalSet(matriz);
    std::cout << matrix.size();
    data.setNumFil(matrix.size());
    data.setNumCol(matrix[0].size());
}

CvsFileReader::~CvsFileReader() {
    //dtor
}

DataFormat CvsFileReader::getFormatoDeDatos(){
    return data;

}

void CvsFileReader::setFormatoDeDatos(DataFormat data){
    this->data = data;
}


void CvsFileReader::read() {
    //dtor
}
