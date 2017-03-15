#ifndef INPUTREADER_H
#define INPUTREADER_H


class InputReader
{
public:
    InputReader();
    virtual ~InputReader();
    virtual void read()=0;
};

#endif // INPUTREADER_H
