#ifndef ALFABETAMIN_H
#define ALFABETAMIN_H

#include <AlfaBeta.h>


class AlfaBetaMin : public AlfaBeta
{
    public:
        AlfaBetaMin(DataFormat d );
        ~AlfaBetaMin();
        void learningMethod();
        int* retrievalMethod(int* pattern, int n);
        void printMatrix();
        void printOutputVectors();
        void printFundamentalSet();
    protected:
    private:
};

#endif // ALFABETAMIN_H
