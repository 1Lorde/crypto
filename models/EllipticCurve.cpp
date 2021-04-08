//
// created by Vlad Savchuk on 11/12/2020.
//

#include "EllipticCurve.h"

EllipticCurve::EllipticCurve(long long a, long long b, long long p) {
    this->a = a;
    this->b = b;
    this->p = p;
}

std::ostream &operator<<(std::ostream &os, const EllipticCurve &curve) {
    os << "y^2 = x^3 + " << curve.a << "x + " << curve.b << " (mod " << curve.p << ")";
    return os;
}

