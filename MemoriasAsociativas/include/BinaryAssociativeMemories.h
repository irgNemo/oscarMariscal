#ifndef MEMORIASASOCIATIVASBINARIAS_H
#define MEMORIASASOCIATIVASBINARIAS_H

#include <AssociativeMemories.h>


class BinaryAssociativeMemories : public AssociativeMemories
{
protected:
    int ** matrix;
    int ** outputVector;
public:

    BinaryAssociativeMemories(DataFormat d):AssociativeMemories(d)
    {
        data = d;
        matrix = new int*[data.getNumFil()];
        for(int i = 0; i < data.getNumFil(); ++i)
        {
            matrix[i] = new int[data.getNumCol()];
        }
        cantMatrixRows = data.getNumFil();
        cantColMatriz = data.getNumCol();
    }

    ~BinaryAssociativeMemories()
    {
        for(int i = 0; i < data.getNumFil(); ++i)
        {
            delete [] matrix[i];
        }
        delete [] matrix;
    };

    int **getMatriz()
    {
        return matrix;
    };

    void setMatriz(int ** m)
    {
        matrix = m;
    };
    int **& getVectorSalida()
    {
        return outputVector;
    };
    void setVectorSalida(int ** v)
    {
        outputVector=v;
    };
};

#endif // MEMORIASASOCIATIVASBINARIAS_H
