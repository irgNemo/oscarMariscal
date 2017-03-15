#include "LearnMatrixComplete.h"

LearnMatrixComplete::LearnMatrixComplete(DataFormat d): LearnMatrix(d){
    sumVector = new int[data.getNumFil()];
}

/** \brief Where the learning happens, and also the sum vector is created
 *
 * \param
 * \param
 * \return
 *
 */

void LearnMatrixComplete::learningMethod(){
    LearnMatrix::learningMethod();
    /**< Obtaining the sum vector */
    for (int i = 0 ; i < cantMatrixRows; i++){
        sumVector[i]=0;
        for (int j = 0; j < cantColMatriz; j++){
            if (matrix[i][j]>0){
                sumVector[i]+=matrix[i][j];
            }
        }
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int* LearnMatrixComplete::retrievalMethod(int* pattern, int n){
    int *result = LearnMatrix::retrievalMethod(pattern,n);
    /**< obtaining the lowest number */
    int lowestNumber=0;
    for (int i =0 ; i < cantMatrixRows;i++){
        if (result!=0 &&  sumVector[i]< lowestNumber ){
            lowestNumber=sumVector[i];
        }
    }

    for (int i = 0 ; i < cantMatrixRows; i++){
        if (result[i]!=0 && sumVector[i]==lowestNumber)
            result[i]=1;
        else
            result[i]=0;
    }
    return result;
}
