//
// created by Vlad Savchuk on 25/9/20.
//

#include <tuple>
#include <algorithm>
#include <iostream>
#include "ModularArithmetic.h"
#include "chrono"
#include "random"

using namespace std;

//convert decimal number to binary
string ModularArithmetic::decimalToBinary(long long decimal) {
    string result;
    while (decimal != 0){
        long long remainder = decimal % 2;
        if (remainder)
            result += "1";
        else
            result += "0";
        decimal /= 2;
    }
    reverse(result.begin(), result.end());

    return result;
}

//find non-negative n (64 bit)
long long ModularArithmetic::unsignedMod(long long a, long long p) {
    long long res = a % p;
    while (res < 0) {
        res = p + res;
    }

    return res;
}

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

//find multiplication inverse of element via Extended Euclidean algorithm (64 bit)
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

//find big power of Number with modulo via Horner`s method
long long ModularArithmetic::hornerPow(long long x, long long y, long long mod) {
    string power = decimalToBinary(y);
    reverse(power.begin(), power.end());

    long squares [power.length()];
    squares[0] = x;

    for (int i = 1; i < power.length(); ++i)
        squares[i] = unsignedMod(pow(squares[i-1], 2), mod);

    long long result = 1;
    for (int i = 0; i < power.length(); ++i){
        long partialCalc = squares[i] * (power[i] - '0');
        result *= partialCalc ? partialCalc : 1;
        result = unsignedMod(result, mod);
    }

    return result;
}

//find big power of Number with modulo via Horner`s method verbosely
long long ModularArithmetic::hornerPowVerbose(long long x, long long y, long long mod) {
    string power = decimalToBinary(y);
    cout << endl << "1) Converting decimal pow " << y << " to binary: (" << y << ")_10 --> (" << power << ")_2" << endl;
    reverse(power.begin(), power.end());

    cout << endl << "2) Building table:" << endl;
    cout << "i  |\t";
    for (int i = 0; i < power.length(); ++i)
        cout << i << "\t";

    long squares [power.length()];
    squares[0] = x;
    for (int i = 1; i < power.length(); ++i)
        squares[i] = unsignedMod(pow(squares[i-1], 2), mod);

    cout << endl << "2  |\t";
    for (int i = 0; i < power.length(); ++i)
        cout << squares[i] << "\t";

    cout << endl << "Xi |\t";
    for (int i = 0; i < power.length(); ++i)
        cout << power[i] - '0' << "\t";

    cout << endl << endl << "3) Calculate result:" << endl << "y= ";

    long long result = 1;
    for (int i = 0; i < power.length(); ++i){
        long partialCalc = squares[i] * (power[i] - '0');
        cout << partialCalc << " * ";
        result *= partialCalc ? partialCalc : 1;
        result = unsignedMod(result, mod);
    }
    cout << "\b\b" << "" << "= " << result << " (mod " << mod << ").";

    return result;}




