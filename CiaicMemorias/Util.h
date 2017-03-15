#ifndef UTIL_H
#define UTIL_H
#include "DataFormat.h"


class Util
{

public:
    Util();
    int * getRandomBinaryArray(int sizeOfArray);
    static void testLearnMatrix();
    static void testAlphaBethaMax();
    static void testAlphaBethaMaxComplete();
    static void oneHot(DataFormat data,int **& outputVector);
};

#endif // UTIL_H
