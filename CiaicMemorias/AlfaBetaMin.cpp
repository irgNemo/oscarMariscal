#include "AlfaBetaMin.h"

#include <iostream>
#include <climits>
using namespace std;
AlfaBetaMin::AlfaBetaMin(DataFormat d ):AlfaBeta(d)
{
    //ctor
}

AlfaBetaMin::~AlfaBetaMin()
{
    //dtor
}
/** \brief In this method the learning is made, according to the alpha method
 *
 */

void AlfaBetaMin::learningMethod() {
    //TODO there's a mistake in this part, currently it only works int  n x n matrix
    cout << "---------------------------------"<< endl;
    int ** fundamentalSet = data.getFundamentalSet();
    for (int i = 0 ; i< cantMatrixRows; i++) {
        for (int j = 0 ; j < cantColMatriz; j++) {
            for (int k = 0 ; k < cantColMatriz; k++) {
                /**< also applying the max operation, only replaced the matrix
                number if the alpha is bigger.*/
                cout <<  outputVector[i][j]<< "," << fundamentalSet[i][k] ;
                int alphaResult = alpha(outputVector[i][j],fundamentalSet[i][k]);
                cout << "=" << alphaResult << " ";
                if (alphaResult < matrix[j][k]){
                    matrix[j][k]= alphaResult;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "---------------------------------"<< endl;
}
/** \brief returns the class depending on the pattern introduced. uses the beta operation defined as such:
 * \param Pattern to search for.
 * \param Size of said pattern.
 * \return returns a vector.
 *
 */

int* AlfaBetaMin::retrievalMethod(int* pattern, int n) {
    cout << endl << "+++++++++++++++++++++++++" << endl;
    int endMatrix[cantMatrixRows][cantColMatriz];
    int *patternToReturn = new int[n];
    /**< initializing in int max the endMatrix, and patter to return */
    for (int i = 0 ; i< cantMatrixRows; i++) {
        for (int j = 0 ; j < cantColMatriz; j++) {
            endMatrix[i][j]=INT_MIN;
            patternToReturn[j]=INT_MIN;
        }
    }
    for (int i = 0 ; i< cantMatrixRows; i++) {
        for (int j = 0 ; j < cantColMatriz; j++) {
            /**< we're also obtaining the min. */
            int betaResult  = betha(matrix[i][j], pattern[i]);
            cout << matrix[i][j] << "," << pattern[j];
            cout << "= "<< betaResult << " ";
            if (betaResult > endMatrix[i][j])
                endMatrix[i][j]=betaResult;
        }
        cout << endl;
    }

    for (int i =  0 ; i < cantMatrixRows; i++) {
        for (int j = 0 ; j < cantColMatriz; j++) {
            if (endMatrix[i][j] < patternToReturn[j])
                patternToReturn [j] = endMatrix[i][j];
        }
    }
    //TODO remove only for testing
    cout << endl;
    for (int i = 0 ; i  < data.getNumCol(); i++){
        cout << patternToReturn[i] << ", ";
    }
    cout << endl << "+++++++++++++++++++++++++" << endl;
    return patternToReturn;
}


/** \brief method for testing purposes, prints the "M" matrix
*
*/
void AlfaBetaMin::printMatrix() {
    for (int i = 0; i < data.getNumFil() ; i++) {
        for (int j = 0 ; j < data.getNumCol() ; j++) {
            std::cout << matrix[i][j] << ":" ;
        }
        std::cout << std::endl;
    }
}

/** \brief Method for testing purposes, prints the outputVectors created
with oneHot to console
 *
 *
 */
void AlfaBetaMin::printOutputVectors() {
    for (int i = 0; i < data.getNumFil() ; i++) {
        for (int j = 0 ; j < data.getNumFil() ; j++) {
            std::cout << outputVector[i][j] << ":" ;
        }
        std::cout << std::endl;
    }
}


/** \brief Prints the fundamental set to console
 *
 */
void AlfaBetaMin::printFundamentalSet() {
    int ** conjuntoFundamental;
    conjuntoFundamental = data.getFundamentalSet();

    for (int i = 0; i < cantMatrixRows ; i++) {
        for (int j = 0 ; j < cantColMatriz ; j++) {
            std::cout << conjuntoFundamental[i][j] << ":" ;
        }
        std::cout << std::endl;
    }
}
