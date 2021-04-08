//
// created by Vlad Savchuk on 11/12/2020.
//

#ifndef SAVCHUK_ELLIPTICCURVEUTILS_H
#define SAVCHUK_ELLIPTICCURVEUTILS_H


#include <tuple>
#include <list>
#include <EllipticCurve.h>

class EllipticCurveUtils {
public:
    std::list<EllipticCurve> findCoefficientsWithPrimeCountOfPoints(int p);
};


#endif //SAVCHUK_ELLIPTICCURVEUTILS_H
