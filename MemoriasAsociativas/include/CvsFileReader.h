#ifndef CVSFILEREADER_H
#define CVSFILEREADER_H

#include <InputFileReader.h>
#include <string>

using std::string;

class CvsFileReader : public InputFileReader
{
    string header;
    string namesOfAtributes[];
    string namesOfClasses[];

    public:
        CvsFileReader();
        virtual ~CvsFileReader();
        void read();

};

#endif // CVSFILEREADER_H
