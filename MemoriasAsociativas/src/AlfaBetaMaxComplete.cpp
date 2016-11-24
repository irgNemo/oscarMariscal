#include "AlfaBetaMaxComplete.h"

AlfaBetaMaxComplete::AlfaBetaMaxComplete(DataFormat d): AlfaBetaMax(d){
    sumVector = new int[data.getNumFil()];
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void AlfaBetaMaxComplete::learningMethod(){
    AlfaBetaMax::learningMethod();
    /**< Obtaining the sum vector */
    for (int i = 0 ; i < cantMatrixRows; i++){
        sumVector[i]=0;
        for (int j = 0; j < cantColMatriz; j++){
            if (matrix[i][j]==1){
                sumVector[i]+=1;
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

int* AlfaBetaMaxComplete::retrievalMethod(int* pattern, int n){
    int *result = AlfaBetaMax::retrievalMethod(pattern,n);
    /**< obtaining the biggest number */
    int biggestNumber=0;
    for (int i =0 ; i < cantMatrixRows;i++){
        if ( sumVector[i]> biggestNumber ){
            biggestNumber=sumVector[i];
        }
    }

    for (int i = 0 ; i < cantMatrixRows; i++){
        if (result!=0 && sumVector[i]==biggestNumber && result[i] == 1)
            result[i]=1;
        else
            result[i]=0;
    }
}
