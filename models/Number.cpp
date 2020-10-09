//
// created by Vlad Savchuk on 25/09/20.
//

#include "Number.h"
#include "../exceptions/NegativeModuloException.h"

// Constructor of Number: a, n - 64 bit integers
Number::Number(long long a, long long n) {
    if (n < 1)
        throw NegativeModuloException(n);

    this->a = ModularArithmetic::unsignedMod(a, n);
    this->n = n;
}

// Find multiplication inverse for Number^-1
Number Number::getInverse() const {
    long long inverse = ModularArithmetic::findInverseElement(this->a, this->n);
    inverse = ModularArithmetic::unsignedMod(inverse, this->n);
    return {inverse, this->n};
}

//
// Operators overloading
//
Number operator+(Number n1, Number n2) {
    if (n1.n == n2.n)
        return {ModularArithmetic::unsignedMod(n1.a + n2.a, n1.n), n1.n};
    throw NotSameModuloException();
}

Number operator+(Number n1, int n2) {
    return {ModularArithmetic::unsignedMod(n1.a + n2, n1.n), n1.n};
}

Number operator-(Number n1, Number n2) {
    if (n1.n == n2.n)
        return {ModularArithmetic::unsignedMod(n1.a - n2.a, n1.n), n1.n};
    throw NotSameModuloException();
}

Number operator-(Number n1, int n2) {
    return {ModularArithmetic::unsignedMod(n1.a - n2, n1.n), n1.n};
}

Number operator*(Number n1, Number n2) {
    if (n1.n == n2.n)
        return {ModularArithmetic::unsignedMod(n1.a * n2.a, n1.n), n1.n};
    throw NotSameModuloException();
}

Number operator*(Number n1, int n2) {
    return {ModularArithmetic::unsignedMod(n1.a * n2, n1.n), n1.n};
}

Number operator/(Number n1, Number n2) {
    if (n1.n == n2.n)
        return {n1.a * ModularArithmetic::findInverseElement(n2.a, n1.n), n1.n};
    throw NotSameModuloException();
}

Number operator/(Number n1, int n2) {
    return {n1.a * ModularArithmetic::findInverseElement(n2, n1.n), n1.n};
}

std::ostream &operator<<(std::ostream &strm, Number number) {
    return strm << number.a << " mod " << number.n;
}






