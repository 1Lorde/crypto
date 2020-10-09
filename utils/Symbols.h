#ifndef SYMBOLS_SYMBOLS_H
#define SYMBOLS_SYMBOLS_H

#include "ModularArithmetic.h"

/*
 *  Class that represents Legendre and Jacobi symbols.
 *
 *  created by Vlad Savchuk on 22/09/20.
 */
class Symbols {
private:
    ModularArithmetic moduloMath;

public:
    //find Legendre Symbol without hints
    long long legendre(long long a, long long p);

    //find Legendre Symbol with explanation
    long long legendreVerbose(long long a, long long p);

    //find Jacobi Symbol without hints
    long long jacobi(long long a, long long P);

    //find Jacobi Symbol with explanation
    long long jacobiVerbose(long long a, long long P);
};

#endif //SYMBOLS_SYMBOLS_H
