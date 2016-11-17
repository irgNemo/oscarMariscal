#ifndef ALFABETAMAX_H
#define ALFABETAMAX_H

#include <AlfaBeta.h>

using namespace std;
class AlfaBetaMax : public AlfaBeta
{
    public:
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
