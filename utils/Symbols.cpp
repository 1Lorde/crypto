//
// created by Vlad Savchuk on 22/09/20.
//

#include <iostream>
#include "list"
#include "cmath"
#include "Symbols.h"

using namespace std;


//find Legendre Symbol without hints
long long Symbols::legendre(long long a, long long p) {
    list<long long> symbols = {};

    if (a == -1)
        return pow(-1, (p - 1) / 2);

    if (a < 0) {
        symbols.push_back(legendre(-1, p));
        a = -1 * a;
    }

    if (a % p == 0)
        return 0;

    if (a > p)
        a = a % p;

    if (a == 1)
        return 1;

    if (a == 2)
        return pow(-1, (p * p - 1) / 8);

    list<long long> factors = moduloMath.getFactors(a);
    if (factors.size() == 1) {
        long long k = pow(-1, ((a - 1) / 2) * ((p - 1) / 2));
        return k * legendre(p, a);
    }

    list<long long> uniqueFactors = list<long long>(factors);
    uniqueFactors.unique();
    list<long long> finalFactors = {};

    for (long long ufactor: uniqueFactors) {
        long long counter = 0;
        for (long long factor: factors) {
            if (ufactor == factor) {
                counter++;
            }
        }
        if (counter % 2 != 0)
            finalFactors.push_back(ufactor);
        else
            symbols.push_back(1);
    }

    for (long long factor : finalFactors)
        symbols.push_back(legendre(factor, p));

    long long result = 1;
    for (long long symbol : symbols)
        result *= symbol;

    return result;
}

//find Legendre Symbol with explanation
long long Symbols::legendreVerbose(long long a, long long p) {
    long long initialA = a;
    list<long long> symbols = {};


    if (a == -1) {
        cout << "L(" << a << "," << p << ") = " << pow(-1, (p - 1) / 2)
             << ", \t\tbecause: L(-1,p) = (-1)^[(p-1)/2]."
             << endl;
        return pow(-1, (p - 1) / 2);
    }

    if (a < 0) {
        cout << endl << "====== L(" << a << "," << p << ") ======" << endl;
        cout << "L(" << a << "," << p << ") = " << "L(-1," << p << ") * L(" << -a << "," << p << ")" << endl;
        symbols.push_back(legendreVerbose(-1, p));
        a = -1 * a;
    }

    if (a > p) {
        cout << endl << "a = " << a << " mod " << p << " = " << a % p << endl;
        a = a % p;
    }

    if (a % p == 0) {
        cout << "L(" << a << "," << p << ") = " << 0 << ", \t\tbecause: a mod p = 0." << endl;
        return 0;
    }

    if (a == 1) {
        cout << "L(" << a << "," << p << ") = " << 1 << ", \t\tbecause: L(1,p) = 1." << endl;
        return 1;
    }

    if (a == 2) {
        cout << "L(" << a << "," << p << ") = " << pow(-1, (p * p - 1) / 8)
             << ", \t\tbecause: L(2,p) = (-1)^[(p^2-1)/8]." << endl;
        return pow(-1, (p * p - 1) / 8);
    }
    cout << endl << "====== L(" << a << "," << p << ") ======" << endl;

    list<long long> factors = moduloMath.getFactors(a);

    if (factors.size() == 1) {
        long long k = pow(-1, ((a - 1) / 2) * ((p - 1) / 2));
        cout << "L(" << a << "," << p << ") = " << k << " * " << "L(" << p << "," << a << ")"
             << ", \t\tbecause: L(p,q) = (-1)^[((p-1)/2)*((q-1)/2)] * L(q,p)." << endl;
        return k * legendreVerbose(p, a);
    } else {
        cout << "L(" << a << "," << p << ") = ";
        for (long long factor : factors) {
            cout << "L(" << factor << "," << p << ") * ";
        }
        cout << "\b\b" << " " << endl;
    }

    list<long long> uniqueFactors = list<long long>(factors);
    uniqueFactors.unique();
    list<long long> finalFactors = {};

    for (long long ufactor: uniqueFactors) {
        long long counter = 0;
        for (long long factor: factors) {
            if (ufactor == factor) {
                counter++;
            }
        }
        if (counter % 2 != 0) {
            finalFactors.push_back(ufactor);
        } else {
            symbols.push_back(1);
            cout << "L(" << ufactor << "^" << counter << "," << p << ") = 1, \t\tbecause: L(a^2,p) = 1." << endl;
        }
    }

    for (long long factor : finalFactors) {
        symbols.push_back(legendreVerbose(factor, p));
    }

    cout << endl << "======================" << endl;
    cout << "L(" << initialA << "," << p << ") = ";

    if (initialA < 0)
        cout << "L(-1," << p << ") * ";

    for (long long factor : factors) {
        cout << "L(" << factor << "," << p << ") * ";
    }
    if (factors.size() > 1)
        cout << "\b\b" << "= ";


    long long result = 1;
    for (long long symbol : symbols) {
        cout << symbol << " * ";
        result *= symbol;
    }
    if (symbols.size() > 1)
        cout << "\b\b" << "= " << result << "." << endl;
    else
        cout << "\b\b" << " " << endl;


    return result;
}

//find Jacobi Symbol without hints
long long Symbols::jacobi(long long a, long long P) {
    list<long long> symbols = {};

    list<long long> factors = moduloMath.getFactors(P);
    for (long long factor : factors) {
        symbols.push_back(legendre(a, factor));
    }

    long long result = 1;
    for (long long symbol : symbols)
        result *= symbol;

    return result;
}

//find Jacobi Symbol with explanation
long long Symbols::jacobiVerbose(long long a, long long P) {
    list<long long> symbols = {};

    list<long long> factors = moduloMath.getFactors(P);

    cout << endl << "====== J(" << a << "," << P << ") ======" << endl;
    cout << "J(" << a << "," << P << ") = ";
    for (long long factor : factors)
        cout << "J(" << a << "," << factor << ") * ";


    if (factors.size() > 1)
        cout << "\b\b\b" << "." << endl << endl;

    for (long long factor : factors) {
        symbols.push_back(legendreVerbose(a, factor));
    }

    cout << endl << "======================" << endl;
    cout << "J(" << a << "," << P << ") = ";
    for (long long factor : factors) {
        cout << "L(" << a << "," << factor << ") * ";
    }

    if (factors.size() > 1)
        cout << "\b\b" << "= ";


    long long result = 1;
    for (long long symbol : symbols) {
        cout << symbol << " * ";
        result *= symbol;
    }

    if (symbols.size() > 1)
        cout << "\b\b" << "= " << result << "." << endl;
    else
        cout << "\b\b" << " " << endl;

    return result;
}


