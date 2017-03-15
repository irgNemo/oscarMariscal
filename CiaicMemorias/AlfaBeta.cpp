#include "AlfaBeta.h"


/** \brief Set the learning matrix to 0,
 *
 * \param the data format which contains the fundamental set.
 * \param
 * \return
 *
 */

AlfaBeta::AlfaBeta(DataFormat d):BinaryAssociativeMemories(d)
{
    for (int i =0 ; i < data.getNumFil(); i++)
    {
        for (int j = 0 ; j < data.getNumCol(); j++)
        {
            matrix[i][j]=0;
        }
    }
}

AlfaBeta::~AlfaBeta()
{
    //dtor
}
int AlfaBeta::alpha(int x, int y)
{
    int alpha;
    if (x == 0 && y == 0) {
        alpha=1;
    }
    else if (x == 0 && y == 1) {
        alpha=0;
    }
    else if (x == 1 && y == 0) {
        alpha=2;
    }
    else if (x == 1 && y == 1) {
        alpha=1;
    }
    return alpha;
}

int AlfaBeta::betha(int x, int y)
{
    int betha;
    if (x == 0 && y == 0) {
        betha=0;
    }
    else if (x == 0 && y == 1) {
        betha=0;
    }
    else if (x == 1 && y == 0) {
        betha=0;
    }
    else if (x == 1 && y == 1) {
        betha=1;
    }
    else if (x == 2 && y == 0) {
        betha=1;
    }
    else if (x == 2 && y == 1) {
        betha=1;
    }
    return betha;
}
