#include "LearnMatrix.h"

#include <QDebug>


LearnMatrix::LearnMatrix(DataFormat d):BinaryAssociativeMemories(d) {
    for (int i =0 ; i < data.getNumFil(); i++) {
        for (int j = 0 ; j < data.getNumCol(); j++) {
            matrix[i][j]=0;
        }
    }
}

void LearnMatrix::learningMethod() {
    for (int i = 0 ; i< cantMatrixRows; i++) {
        for (int j = 0 ; j < cantColMatriz; j++) {
            if (outputVector[i][i] == 1 && data.getFundamentalSet()[i][j] == 1) {
                matrix[i][j]=EPSILON;
            } else if (outputVector[i][i] == 1 && data.getFundamentalSet()[i][j] == 0) {
                matrix[i][j]=-EPSILON;
            } else {
                matrix[i][j]=0;
            }
        }
    }
}

int *LearnMatrix::retrievalMethod(int *pattern, int n) {
    //se crea un vector para determinar el mas grande, para saber que patron de salida devolver.
    int sumaDeLosPatrones[cantMatrixRows];
    for (int i = 0 ; i < cantMatrixRows; i++) {
        sumaDeLosPatrones[i]=0;
    }
    for (int i = 0; i < cantMatrixRows; i++) {
        for (int j = 0; j < cantColMatriz; j++) {
            if (matrix[i][j]==pattern[i])
                sumaDeLosPatrones[i]+=1;
        }
    }
    //Buscando el elemento mayor para devolver el patron correcto;
    int mayor =0;
    for (int i = 0 ; i < cantMatrixRows; i++) {
        if (sumaDeLosPatrones[i]>sumaDeLosPatrones[mayor])
            mayor=i;
    }
    return outputVector[mayor];
}

LearnMatrix::~LearnMatrix() {
}

void LearnMatrix::oneHot() {
    int numberOfPatterns;
    //Creating output patterns
    numberOfPatterns = data.getNumFil();
    outputVector = new int*[numberOfPatterns];
    for(int i = 0; i < numberOfPatterns; ++i) {
        outputVector[i] = new int[numberOfPatterns];
    }
    //Filling the output patterns with according values
    for (int i = 0 ; i< numberOfPatterns; i++) {
        for (int j = 0; j < numberOfPatterns; j++) {
            if (i==j) {
                outputVector[i][j]=1;
            } else {
                outputVector[i][j]=0;
            }
        }
    }
}

void LearnMatrix::printMatrix() {
    QString temp="";
    for (int i = 0; i < data.getNumFil() ; i++) {
        for (int j = 0 ; j < data.getNumCol() ; j++) {
            //qDebug() << matrix[i][j] << ":" ;
            temp.append(QString("%1").arg( matrix[i][j] ) );
            temp.append(":");
        }
        qDebug() << temp;
        temp.clear();
    }
}

void LearnMatrix::printOutputVectors() {
    for (int i = 0; i < data.getNumFil() ; i++) {
        for (int j = 0 ; j < data.getNumFil() ; j++) {
            qDebug() << outputVector[i][j] << ":" ;
        }
        qDebug() << "\n";
    }
}

void LearnMatrix::printFundamentalSet() {
    int ** conjuntoFundamental;
    conjuntoFundamental = data.getFundamentalSet();
    QString temp="";
    for (int i = 0; i < cantMatrixRows ; i++) {
        for (int j = 0 ; j < cantColMatriz ; j++) {
            temp.append(QString("%1").arg( conjuntoFundamental[i][j]));
            temp.append(":") ;
        }
        qDebug() << temp;
        temp.clear();
    }
}
