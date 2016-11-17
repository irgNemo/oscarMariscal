#ifndef LEARNMATRIX_H
#define LEARNMATRIX_H
#define EPSILON 1

#include <BinaryAssociativeMemories.h>
#include <iostream>


class LearnMatrix : public BinaryAssociativeMemories {
public:

    /** \brief This method set the matrix "M" to 0.
     *
     * \param a formatData, which contains the fundamental patterns.
     *
     */
    LearnMatrix(DataFormat d):BinaryAssociativeMemories(d) {
        for (int i =0 ; i < data.getNumFil(); i++) {
            for (int j = 0 ; j < data.getNumCol(); j++) {
                matrix[i][j]=0;
            }
        }
    }



    /** \brief the learning method updates the "M" matrix, depending on the input patterns
     *
     */
    void  learningMethod() {
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

    /** \brief returns an output vector , based upon the pattern passed
     *
     * \param the pattern which ones tries to recognize
     * \return
     *
     */
    int *  retrievalMethod(int* pattern, int n) {
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

    ~ LearnMatrix() {
    }

/** \brief This method creates the output patterns
 *
 */
    void oneHot() {
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

/** \brief method for testing purposes, prints the "M" matrix
 *
 */
    void printMatrix() {
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
    void printOutputVectors() {
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
    void printFundamentalSet() {
        int ** conjuntoFundamental;
        conjuntoFundamental = data.getFundamentalSet();

        for (int i = 0; i < cantMatrixRows ; i++) {
            for (int j = 0 ; j < cantColMatriz ; j++) {
                std::cout << conjuntoFundamental[i][j] << ":" ;
            }
            std::cout << std::endl;
        }
    }
};

#endif // LEARNMATRIX_H
