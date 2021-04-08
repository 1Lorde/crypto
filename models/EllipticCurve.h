#ifndef SAVCHUK_ELLIPTICCURVE_H
#define SAVCHUK_ELLIPTICCURVE_H


#include <ostream>

/*
 *  Class that represent elliptic curve.
 *
 *  created by Vlad Savchuk on 11/12/2020.
 */
class EllipticCurve {
private:
    long long a;
    long long b;
    long long p;

public:
    EllipticCurve(long long a, long long b, long long p);

    long long getA() const {
        return a;
    }

    long long getB() const {
        return b;
    }

    long long getP() const {
        return p;
    }

    friend std::ostream &operator<<(std::ostream &os, const EllipticCurve &curve);
};


#endif //SAVCHUK_ELLIPTICCURVE_H
