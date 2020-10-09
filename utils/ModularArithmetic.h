#ifndef SYMBOLS_MODULARARITHMETIC_H
#define SYMBOLS_MODULARARITHMETIC_H

#include "list"
#include "../exceptions/NoMultiplicationInverseException.h"

/*
 *  Class that represents basic modulo arithmetic operations and functions.
 *
 *  created by Vlad Savchuk on 25/9/20.
 */
class ModularArithmetic {
public:
    //find smallest divisor of Number (64 bit)
    static long long getSmallestDivisor(long long n);

    //number factorization (64 bit)
    static std::list<long long> getFactors(long long n);

    //greatest Common Divisor (64 bit)
    static long long gcd(long long a, long long b);

    //extended Euclidean algorithm (64 bit)
    //return tuple(s,t)
    static std::tuple<long, long> extendedEuclideanAlgorithm(long r1, long r2);

    //find non-negative n (64 bit)
    static long long unsignedMod(long long a, long long p);

    //find big powers of Number with modulo (64 bit)
    static long long moduloPow(long long x, long long y, long long mod);

    //find multiplication inverse of element (64 bit)
    static long long findInverseElement(long long a, long long p);
};

#endif //SYMBOLS_MODULARARITHMETIC_H
