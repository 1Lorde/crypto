//
// created by Vlad Savchuk on 22/10/2020.
//

#include <cmath>
#include "PrimeNumberGenerator.h"

using namespace std;

//finding prime numbers in range N using Sieve of Eratosthenes
list<long long> PrimeNumberGenerator::eratosthenesSieve(long long n) {
    bool *array = new bool[n];
    array[0] = false;   
    array[1] = false;

    for (int i = 2; i < n; ++i)
        array[i] = true;

    for (int i = 2; i < ceil(sqrt(n)); ++i) {
        long long j = 0;

        if (array[i]){
            j = i * i;
            while (j < n){
                array[j] = false;
                j += i;
            }
        }
    }

    list<long long> primeList;

    for (int i = 0; i < n; ++i)
        if (array[i])
            primeList.push_back(i);

    return primeList;
}

