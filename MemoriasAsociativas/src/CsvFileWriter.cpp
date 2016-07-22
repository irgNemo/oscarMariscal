#include "CsvFileWriter.h"
#include <fstream>
#include <iostream>

using namespace std;

CsvFileWriter::CsvFileWriter()
{

}

void CsvFileWriter::write()
{
    ofstream myFile (fileName.c_str(),ios::trunc);
    int** matrix = data.getFundamentalSet();
    int rows=data.getNumFil();
    int columns=data.getNumCol();
    for (int i = 0 ; i < rows ; i++ ){
        for (int j =0; j < columns ; j++){
            int value = matrix[i][j];
            myFile << value;
            if ((j+1)<columns)
                myFile << ",";
        }
        if ((i+1)<rows)
            myFile << "\n";
    }
    myFile.close();
}

