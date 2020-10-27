#ifndef SAVCHUK_PRIMENUMBERUTILS_H
#define SAVCHUK_PRIMENUMBERUTILS_H

#include <list>

/*
 *  Class that represents different useful utilities.
 *
 *  created by Vlad Savchuk on 22/10/2020.
 */
class PrimeNumberUtils {
public:
    //find sequence number of prime using Sieve of Eratosthenes
    static long getSequenceNumberOfPrime(long long primeNumber);

    //find prime number by given sequence number
    static long getPrimeBySeqNumber(long amount);

    //find N primes, starting from 0
    static std::list<long long> findNPrimes(long amount);

    //Goldbach's conjecture
    static std::list<long> goldbachConjecture(long number);

    //Legendre's conjecture
    static std::list<long long> legendreConjecture(long n);
};


#endif //SAVCHUK_PRIMENUMBERUTILS_H
