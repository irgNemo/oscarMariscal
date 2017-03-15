#ifndef ALFABETA_H
#define ALFABETA_H

#include "BinaryAssociativeMemories.h"


class AlfaBeta : public BinaryAssociativeMemories
{
public:
    protected:
    AlfaBeta(DataFormat d);
    ~AlfaBeta();
    int alpha(int x,int y);
    int betha(int x,int y);


private:
};

#endif // ALFABETA_H
