//
// created by Vlad Savchuk on 22/10/2020.
//

#include <NoSolutionsException.h>
#include "PrimeNumberUtils.h"
#include "PrimeNumberGenerator.h"
#include "PrimalityTest.h"
#include <cmath>

using namespace std;

//find sequence number of prime using Sieve of Eratosthenes
long PrimeNumberUtils::getSequenceNumberOfPrime(long long primeNumber) {
    return PrimeNumberGenerator::eratosthenesSieve(primeNumber + 1).size();
}

//find prime number by given sequence number
long PrimeNumberUtils::getPrimeBySeqNumber(long seqNumber) {
    PrimalityTest primalityTest;
    long count = 1;
    long long i = 2;
    while (true) {
        if (primalityTest.lehmann(i, 20))
            count++;

        if (count == seqNumber)
            return i;

        i++;
    }
}

//find N primes, starting from 0
std::list<long long> PrimeNumberUtils::findNPrimes(long amount) {
    PrimalityTest primalityTest;
    list<long long> primes;
    long long i = 2;
    while (true){
        if (primalityTest.lehmann(i, 20))
            primes.push_back(i);

        if (primes.size() == amount)
            break;

        i++;
    }

    return primes;
}

//Goldbach's conjecture
std::list<long> PrimeNumberUtils::goldbachConjecture(long number) {
    if (number % 2 || number < 2)
        throw NoSolutionsException();

    PrimalityTest primalityTest;
    list<long> summands;
    long i = 2;

    for (long j = number-i; j >= 2; j--)
    {
        if (primalityTest.solovayStrassen(i, 20) &&
            primalityTest.solovayStrassen(j, 20)) {

            summands.push_back(i);
            summands.push_back(j);
            break;
        }

        i++;
    }
    return summands;
}

//Legendre's conjecture
std::list<long long> PrimeNumberUtils::legendreConjecture(long n) {
    list<long long> primes;
    PrimalityTest primalityTest;

    for (long long i = pow(n, 2); i < pow(n+1, 2); ++i) {
        if (primalityTest.solovayStrassen(i, 20))
            primes.push_back(i);
    }

    if (primes.empty())
        throw NoSolutionsException();

    return primes;
}
