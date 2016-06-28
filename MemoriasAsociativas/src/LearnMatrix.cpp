#include "LearnMatrix.h"
#include <iostream>

// Se iguala la matriz a 0.
//LearnMatrix::LearnMatrix(FormatoDeDatos d):MemoriasAsociativasBinarias(d)
//{
//    for (int i =0 ; i < datos.getNumFil(); i++){
//        for (int j = 0 ; j < datos.getNumCol(); j++){
//            matriz[i][j]=0;
//        }
//    }
//}
//
////Se actuliza la matriz respuecto al conjunto fundamental de patrones.
//void LearnMatrix:: metodoAprendizaje(){
//    for (int i = 0 ; i< filMatriz;i++){
//        for (int j = 0 ; j < colMatriz; j++){
//            if (vectoresSalida[i][i] == 1 && datos.getConjuntoFundamental()[i][j] == 1){
//                matriz[i][j]=EPSILON;
//            }
//            else if (vectoresSalida[i][i] == 1 && datos.getConjuntoFundamental()[i][j] == 0){
//                matriz[i][j]=-EPSILON;
//            }
//            else{
//                matriz[i][j]=0;
//            }
//        }
//    }
//}
//
////Se pasa un patron a reconocer y se regresa una salida
//int * LearnMatrix:: metodoRecuperacion(int* patron, int n){
//    //se crea un vector para determinar el mas grande, para saber que patron de salida devolver.
//    int sumaDeLosPatrones[filMatriz];
//    for (int i = 0 ; i < filMatriz; i++){
//        sumaDeLosPatrones[i]=0;
//    }
//    for (int i = 0; i < filMatriz; i++){
//        for (int j = 0; j < colMatriz; j++){
//            if (matriz[i][j]==patron[i])
//                sumaDeLosPatrones[i]+=1;
//        }
//    }
//    //Buscando el elemento mayor para devolver el patron correcto;
//    int mayor =0;
//    for (int i = 0 ; i < filMatriz; i++){
//        if (sumaDeLosPatrones[i]>sumaDeLosPatrones[mayor])
//            mayor=i;
//    }
//    return vectoresSalida[mayor];
//}
//
//LearnMatrix:: ~ LearnMatrix(){
//}
//
////Aquí se crean los vectores de salida.
//void LearnMatrix::oneHot(){
//    int numeroDePatrones;
//    //Creando los vectores de salida
//    numeroDePatrones = datos.getNumFil();
//    vectoresSalida = new int*[numeroDePatrones];
//    for(int i = 0; i < numeroDePatrones; ++i){
//        vectoresSalida[i] = new int[numeroDePatrones];
//    }
//    //llenando con valores correctos segun el metodo de oneHot
//    for (int i = 0 ; i< numeroDePatrones; i++){
//        for (int j = 0; j < numeroDePatrones; j++){
//            if (i==j){
//                vectoresSalida[i][j]=1;
//            }
//            else{
//                vectoresSalida[i][j]=0;
//            }
//        }
//    }
//
//}
//
//
//void LearnMatrix::imprimirMatriz(){
//    for (int i = 0; i < datos.getNumFil() ;i++){
//        for (int j = 0 ; j < datos.getNumCol() ; j++){
//            std::cout << matriz[i][j] << ":" ;
//        }
//        std::cout << std::endl;
//    }
//}
//
//void LearnMatrix::imprimirVectorSalida()
//{
//    for (int i = 0; i < datos.getNumFil() ;i++){
//        for (int j = 0 ; j < datos.getNumFil() ; j++){
//            std::cout << vectoresSalida[i][j] << ":" ;
//        }
//        std::cout << std::endl;
//    }
//}
//
//void LearnMatrix::imprimirConjuntoFunamental()
//{
//    int ** conjuntoFundamental;
//    conjuntoFundamental = datos.getConjuntoFundamental();
//
//    for (int i = 0; i < filMatriz ;i++){
//        for (int j = 0 ; j < colMatriz ; j++){
//            std::cout << conjuntoFundamental[i][j] << ":" ;
//        }
//        std::cout << std::endl;
//    }
//
//}


