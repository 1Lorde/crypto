//
// created by Vlad Savchuk on 11/12/2020.
//

#include <cmath>
#include "EllipticCurveUtils.h"
#include "ModularArithmetic.h"
#include "Symbols.h"
#include "PrimalityTest.h"

using namespace std;

list<EllipticCurve> EllipticCurveUtils::findCoefficientsWithPrimeCountOfPoints(int p) {
    Symbols symbols;
    PrimalityTest primalityTest;

    list<EllipticCurve> result = list<EllipticCurve>();

    int Fx;
    for (int a = 1; a < p; a++){
        for (int b = 1; b < p; b++){
            int n = 1;
            for (int x = 0; x < p; x++){
                Fx = pow(x, 3) + a * x + b;
                Fx = ModularArithmetic::unsignedMod(Fx, p);

                int L = symbols.legendre(Fx, p);
                if (L == 0) {
                    n++;
                }
                if (L == 1) {
                    n += 2;
                }
            }

            if (primalityTest.solovayStrassen(n, 20)){
                result.push_back(EllipticCurve(a, b, n));
            }
        }
    }
    return result;
}
