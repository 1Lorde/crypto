//
// created by Vlad Savchuk on 25/09/20.
//

#include <iostream>
#include <cmath>
#include <chrono>
#include <random>
#include "PrimalityTest.h"

using namespace std;


//return random Number in range (lower, upper)
long long PrimalityTest::getRandomNumber(long long lower, long long upper) {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937_64 rng(seed);
    uniform_int_distribution<long long> d{lower, upper};
    return d(rng);
}

//Solovay–Strassen primality test without hints
bool PrimalityTest::solovayStrassen(long long n, int k) {
    if ((n % 2 == 0) && n > 2) {
        return false;
    }

    for (long long i = 0; i < k; i++) {
        long long a = getRandomNumber(2, n - 1);

        if (moduloMath.gcd(a, n) > 1)
            return false;

        long long expr1 = moduloMath.moduloPow(a, (n - 1) / 2, n);
        long long expr2 = moduloMath.unsignedMod(symbols.jacobi(a, n), n);
        if (expr1 != expr2)
            return false;
    }

    return true;
}

//Solovay–Strassen primality test with hints
bool PrimalityTest::solovayStrassenVerbose(long long n, int k) {
    if ((n % 2 == 0) && n > 2) {
        return false;
    }

    for (int i = 0; i < k; i++) {
        long long a = getRandomNumber(2, n - 1);
        if (moduloMath.gcd(a, n) > 1) {
            cout << "gcd(a, n) > 1." << endl;
            return false;
        }

        long long expr1 = moduloMath.moduloPow(a, (n - 1) / 2, n);
        long long expr2 = moduloMath.unsignedMod(symbols.jacobi(a, n), n);
        if (expr1 != expr2) {
            cout << "a^[(n - 1)/2] != J(a,n) (n n)." << endl;
            return false;
        }
    }
    cout << n << " is prime with accuracy (1-2^-k) = " << (1 - pow(2, -k)) << "." << endl;
    return true;
}