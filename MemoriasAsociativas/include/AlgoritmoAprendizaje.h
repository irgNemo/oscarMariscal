#ifndef ALGORITMOAPRENDIZAJE_H
#define ALGORITMOAPRENDIZAJE_H


class AlgoritmoAprendizaje
{
    public:
        AlgoritmoAprendizaje();
        virtual void metodoAprendizaje()=0;
        virtual int * metodoRecuperacion(int * patron,int n)=0;
//        virtual ~AlgoritmoAprendizaje()=0;
};

#endif // ALGORITMOAPRENDIZAJE_H
