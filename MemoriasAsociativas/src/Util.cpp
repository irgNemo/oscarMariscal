#include "Util.h"

#include <cstdlib>
#include <ctime>

int* Util::getRandomBinaryArray(int sizeOfArray){
    int* arrayToReturn;
    arrayToReturn = new int[sizeOfArray];
    for (int i = 0 ; i < sizeOfArray; i++){
        arrayToReturn[i]= std::rand()%2;
    }
    return arrayToReturn;

}

Util :: Util(){
    std::srand(std::time(0));
}

