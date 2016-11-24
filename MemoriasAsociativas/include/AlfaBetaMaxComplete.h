#ifndef ALFABETAMAXCOMPLETE_H
#define ALFABETAMAXCOMPLETE_H

#include <AlfaBetaMax.h>


class AlfaBetaMaxComplete : public AlfaBetaMax
{
    public:
        int* sumVector;

        AlfaBetaMaxComplete(DataFormat d);
        void learningMethod();
        int* retrievalMethod(int* pattern, int n);
    protected:
    private:
};

#endif // ALFABETAMAXCOMPLETE_H
