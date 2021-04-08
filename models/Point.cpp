//
// created by Vlad Savchuk on 11/12/2020.
//

#include <cmath>
#include <ModularArithmetic.h>
#include <NoSpecifiedEllipticCurveException.h>
#include "Point.h"

Point::Point(long long x, long long y) {
    this->name = "P";
    this->x = x;
    this->y = y;
    this->ellipticCurve = nullptr;
}

Point::Point(std::string name, long long x, long long y) {
    this->name = name;
    this->x = x;
    this->y = y;
}

Point::Point(std::string name, long long int x, long long int y, EllipticCurve *curve) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->ellipticCurve = curve;
}

Point operator+(Point p, Point q) {
    long long Xp = p.x;
    long long Yp = p.y;
    long long Xq = q.x;
    long long Yq = q.y;

    long long A, modulo;
    if (p.ellipticCurve != nullptr){
        A = p.ellipticCurve->getA();
        modulo = p.ellipticCurve->getP();
    } else if (q.ellipticCurve != nullptr){
        A = q.ellipticCurve->getA();
        modulo = q.ellipticCurve->getP();
    } else{
        throw NoSpecifiedEllipticCurveException();
    }

    long long S, Xr, Yr;

    if (Xp != Xq) {
        //condition (Xp != Xq) --> R = -(P + Q).
        S = (Yp - Yq) * ModularArithmetic::findInverseElement(Xp - Xq, modulo);
        S = ModularArithmetic::unsignedMod(S, modulo);
        Xr = pow(S, 2) - Xp - Xq;
        Yr = -Yp + S * (Xp - Xr);
    }
    else {
        if (Yp == -Yq) {
            //Condition (Yp = Yq = 0) --> P + P = O.
            return Point("O", 0, 0);
        }
        else if (Yp == Yq != 0)
        {
            //condition (Yp = Yq != 0) --> R = -(P + P) = -2P = -2Q.
            S = (3 * pow(Xp, 2) + A) * ModularArithmetic::findInverseElement(2 * Yp, modulo);
            S = ModularArithmetic::unsignedMod(S, modulo);
            Xr = pow(S, 2) - 2 * Xp;
            Yr = -Yp + S * (Xp - Xr);
        }
    }

    Xr = ModularArithmetic::unsignedMod(Xr, modulo);
    Yr = ModularArithmetic::unsignedMod(Yr, modulo);

    return Point("R", Xr, Yr, p.ellipticCurve);
}

Point operator*(long long k, Point p) {
    if (k == 0){
        return Point("O", 0, 0);
    }else if (k == 1){
        return p;
    }else if (k % 2 == 1){
        return p + (k-1) * p;
    }else {
        return (k/2) * (p+p);
    }
}

bool Point::isOnEllipticCurve(EllipticCurve curve) {
    long long leftSide = ModularArithmetic::unsignedMod(pow(y, 2), curve.getP());
    long long rightSide = ModularArithmetic::unsignedMod(pow(x, 3) + curve.getA() * x + curve.getB(), curve.getP());
    if (leftSide == rightSide){
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << point.name << " = (" << point.x << ", " << point.y << ").";
    return os;
}
