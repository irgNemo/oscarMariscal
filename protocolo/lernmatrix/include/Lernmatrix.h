#ifndef LERNMATRIX_H
#define LERNMATRIX_H
#define EPSILON 1


class Lernmatrix
{
    int ** conjuntoFundamental ;
    public:
        Lernmatrix(int x , int y);
        int reglaAprendizaje(int x, int y);
        int reglaRecuperacion();
};

#endif // LERNMATRIX_H
