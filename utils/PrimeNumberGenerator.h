#include <list>

/*
 *  Class that represents prime generators.
 *
 *  created by Vlad Savchuk on 22/10/2020.
 */
class PrimeNumberGenerator {
public:
    //finding prime numbers in range N using Sieve of Eratosthenes
    static std::list<long long> eratosthenesSieve(long long n);
};
