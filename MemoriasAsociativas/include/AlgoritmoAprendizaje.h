#ifndef ALGORITMOAPRENDIZAJE_H
#define ALGORITMOAPRENDIZAJE_H


class LearningAlgorithm
{
    public:
        LearningAlgorithm();
        virtual void learningMethod()=0;
        virtual int * retrievalMethod (int * pattern,int n)=0;
//        virtual ~AlgoritmoAprendizaje()=0;
};

#endif // ALGORITMOAPRENDIZAJE_H
