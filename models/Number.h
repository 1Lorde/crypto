#ifndef SYMBOLS_NUMBER_H
#define SYMBOLS_NUMBER_H

#include <ostream>
#include "../exceptions/NotSameModuloException.h"
#include "../utils/ModularArithmetic.h"

/*
 *  Class that represent integer 64 bit number "a" with modulo "n".
 *
 *  created by Vlad Savchuk on 25/9/20.
 */
class Number {
private:
    //64 bit integer number
    long long a;
    //64 bit integer modulo
    long long n;

public:
    //constructor of Number: a, n - 64 bit integers
    Number(long long a, long long n);

    long long getA() const {
        return this->a;
    }

    long long getN() const {
        return this->n;
    }

    //find multiplication inverse for Number^-1
    Number getInverse() const;

    //operators overloading
    friend Number operator+(Number n1, Number n2);

    friend Number operator+(Number n1, int n2);

    friend Number operator-(Number n1, Number n2);

    friend Number operator-(Number n1, int n2);

    friend Number operator*(Number n1, Number n2);

    friend Number operator*(Number n1, int n2);

    friend Number operator/(Number n1, Number n2);

    friend Number operator/(Number n1, int n2);

    friend std::ostream &operator<<(std::ostream &strm, Number number);
};

#endif //SYMBOLS_NUMBER_H
