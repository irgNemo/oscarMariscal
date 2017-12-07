#ifndef LEARNMATRIX_H
#define LEARNMATRIX_H

#define EPSILON 1

#include "BinaryAssociativeMemories.h"


class LearnMatrix : public BinaryAssociativeMemories
{

    /*
     * This method is used to help in parallel processing in the learning phase
     */
    static void auxLearningConcurrent(int * x, int * y,int* learnMatrixRow, int rowSize);

public:
    /** \brief This method set the matrix "M" to 0.
     *
     * \param a formatData, which contains the fundamental patterns.
     *
     */
    LearnMatrix(DataFormat d);



    /** \brief the learning method updates the "M" matrix, depending on the input patterns
     *
     */
    void  learningMethod();

    /** \brief returns an output vector , based upon the pattern passed
     *
     * \param the pattern which ones tries to recognize
     * \return
     *
     */
    int *  retrievalMethod(int* pattern, int n);

    ~ LearnMatrix();

    /** \brief This method creates the output patterns
     *
     */
    void oneHot();

    /** \brief method for testing purposes, prints the "M" matrix
     *
     */
    void printMatrix();

    /** \brief Method for testing purposes, prints the outputVectors created
    with oneHot to console
     *
     *
     */
    void printOutputVectors();

    /** \brief Prints the fundamental set to console
     *
     */
    void printFundamentalSet();
};

#endif // LEARNMATRIX_H
