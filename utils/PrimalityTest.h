#ifndef SYMBOLS_PRIMALITYTEST_H
#define SYMBOLS_PRIMALITYTEST_H

#include "ModularArithmetic.h"
#include "Symbols.h"

/*
 *  Class that represents primality tests.
 *
 *  created by Vlad Savchuk on 25/09/20.
 */
class PrimalityTest {
private:
    Symbols symbols;

    //return random Number in range (lower, upper)
    static long long getRandomNumber(long long lower, long long upper);

public:
    //Solovay–Strassen primality test without hints
    bool solovayStrassen(long long n, int k);

    //Solovay–Strassen primality test with hints
    bool solovayStrassenVerbose(long long n, int k);

    //Fermat primality test without hints
    bool fermat(long long n, int k);

    //Fermat primality test with hints
    bool fermatVerbose(long long n, int k);

    //Lehmann`s primality test without hints
    bool lehmann(long long n, int k);

    //Lehmann`s primality test with hints
    bool lehmannVerbose(long long n, int k);
};

#endif //SYMBOLS_PRIMALITYTEST_H
