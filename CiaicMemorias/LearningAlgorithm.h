#ifndef LEARNINGALGORITHM_H
#define LEARNINGALGORITHM_H


class LearningAlgorithm
{
public:
    LearningAlgorithm();
    virtual void learningMethod()=0;
    virtual int * retrievalMethod (int * pattern,int n)=0;
};

#endif // LEARNINGALGORITHM_H
