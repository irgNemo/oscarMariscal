#ifndef ALFABETAMAX_H
#define ALFABETAMAX_H


#include "AlfaBeta.h"

using namespace std;
class AlfaBetaMax : public AlfaBeta
{
    public:
        /**< This attribute is here so that when the retrieval method is called
        the recall matrix is saved so it dons't has to be recalculated for this class specializations*/
        int **endMatrix;
        AlfaBetaMax(DataFormat d);
        virtual ~AlfaBetaMax();
        void oneHot();

        void learningMethod();
        int* retrievalMethod(int* pattern, int n);
        void printMatrix();
        void printOutputVectors();
        void printFundamentalSet();
protected:
    private:
};


#endif // ALFABETAMAX_H
