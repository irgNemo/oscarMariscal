#ifndef LEARNMATRIXCOMPLETE_H
#define LEARNMATRIXCOMPLETE_H

#include <LearnMatrix.h>


class LearnMatrixComplete : public LearnMatrix
{
    public:
        int * sumVector;
        LearnMatrixComplete(DataFormat d);
        void learningMethod();
        int* retrievalMethod(int* pattern, int n);
    protected:
    private:
};

#endif // LEARNMATRIXCOMPLETE_H
