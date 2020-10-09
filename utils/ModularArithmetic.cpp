//
// created by Vlad Savchuk on 25/9/20.
//

#include <tuple>
#include "ModularArithmetic.h"
#include "chrono"
#include "random"

using namespace std;

//find smallest divisor of Number (64 bit)
long long ModularArithmetic::getSmallestDivisor(long long n) {
    long long d = 2;
    while (n % d != 0) {
        d = d + 1;
    }
    return d;
}

//number factorization (64 bit)
list<long long> ModularArithmetic::getFactors(long long n) {
    list<long long> factors = {};
    while (n != 1) {
        long long p = getSmallestDivisor(n);
        factors.push_back(p);
        n = n / p;
    }
    return factors;
}

//greatest common divisor via Euclidean algorithm (64 bit)
long long ModularArithmetic::gcd(long long a, long long b) {
    long long q = 0;
    long long r1 = a;
    long long r2 = b;
    long long r = 0;

    if (a < b) {
        r1 = b;
        r2 = a;
    }

    while (r2 != 0) {
        q = r1 / r2;
        r = r1 % r2;
        r1 = r2;
        r2 = r;
    }

    return r1;
}

//extended Euclidean algorithm (64 bit)
//return tuple(s,t)
tuple<long, long> ModularArithmetic::extendedEuclideanAlgorithm(long r1, long r2){
    int q = 0;
    int r = 0;
    int s1 = 1;
    int s2 = 0;
    int s = 0;
    int t1 = 0;
    int t2 = 1;
    int t = 0;

    while (r2 != 0){
        q = r1 / r2;
        r = r1 % r2;
        s = s1 - q*s2;
        t = t1 - q*t2;
        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }

    return make_tuple(s1, t1);
}

//find non-negative n (64 bit)
long long ModularArithmetic::unsignedMod(long long a, long long p) {
    long long res = a % p;
    while (res < 0) {
        res = p + res;
    }

    return res;
}

//find big powers of number with modulo (64 bit)
long long ModularArithmetic::moduloPow(long long x, long long y, long long mod) {
    list<long long> multipliers = {};
    while (y != 1) {
        if (y % 2 != 0)
            multipliers.push_back(x);
        x = x * x;
        y = y / 2;
        if (x > mod)
            x = x % mod;
    }

    for (long long m : multipliers) {
        x *= m;

        if (x > mod)
            x = x % mod;
    }

    return x;
}

//find multiplication inverse of element (64 bit)
long long ModularArithmetic::findInverseElement(long long int a, long long int p) {
    long long q = 0;
    long long r1 = p;
    long long r2 = a;
    long long r = 0;
    long long t1 = 0;
    long long t2 = 1;
    long long t = 0;

    if (gcd(p, a) == 1) {
        while (r2 != 0) {
            q = r1 / r2;
            r = r1 % r2;
            t = t1 - q * t2;
            r1 = r2;
            r2 = r;
            t1 = t2;
            t2 = t;
        }
        return t1;
    } else {
        throw NoMultiplicationInverseException(a, p);
    }
}





