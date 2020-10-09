//
// created by Vlad Savchuk on 01/10/2020.
//

#include <tuple>
#include "ChineseRemainderTheorem.h"
#include "../exceptions/NoSolutionsException.h"

using namespace std;

//find partial solution for two equations (Numbers)
long long ChineseRemainderTheorem::getPartialSolution(Number num1, Number num2) {
    if (!ModularArithmetic::gcd(num1.getN(), num2.getN()))
        throw NoSolutionsException();

    long long x1 = num1.getA();
    long long n1 = num1.getN();
    long long x2 = num2.getA();
    long long n2 = num2.getN();
    long long u, v;

    tie(u, v) = ModularArithmetic::extendedEuclideanAlgorithm(n1, n2);

    //partial solution
    long long x = u * n1 * x2 + v * n2 * x1;

    return x;
}

//find partial canonical solution for two equations (Numbers)
long long ChineseRemainderTheorem::getPartialCanonicalSolution(Number num1, Number num2) {
    long long x = getPartialSolution(num1, num2);
    long long n = num1.getN() * num2.getN();

    //partial canonical solution
    long long x0 = ModularArithmetic::unsignedMod(x, n);

    return x0;
}

//find general solution for two equations (Numbers)
string ChineseRemainderTheorem::getGeneralSolution(Number num1, Number num2) {
    string x = to_string(getPartialSolution(num1, num2));
    string n = to_string(num1.getN() * num2.getN());

    return x + " + " + n + "k";
}

//find general canonical solution for two equations (Numbers)
string ChineseRemainderTheorem::getGeneralCanonicalSolution(Number num1, Number num2) {
    string x0 = to_string(getPartialCanonicalSolution(num1, num2));
    string n = to_string(num1.getN() * num2.getN());

    return x0 + " + " + n + "k";
}
