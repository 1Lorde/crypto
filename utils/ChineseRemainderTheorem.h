#ifndef SYMBOLS_CHINESEREMAINDERTHEOREM_H
#define SYMBOLS_CHINESEREMAINDERTHEOREM_H

#include "../models/Number.h"

/*
 *  Class that represents Chinese Remainder Theorem algorithm.
 *
 *  created by Vlad Savchuk on 01/10/2020.
 */
class ChineseRemainderTheorem {
public:
    //find partial solution for two equations (Numbers)
    long long getPartialSolution(Number num1, Number num2);

    //find partial canonical solution for two equations (Numbers)
    long long getPartialCanonicalSolution(Number num1, Number num2);

    //find general solution for two equations (Numbers)
    std::string getGeneralSolution(Number num1, Number num2);

    //find general canonical solution for two equations (Numbers)
    std::string getGeneralCanonicalSolution(Number num1, Number num2);
};


#endif //SYMBOLS_CHINESEREMAINDERTHEOREM_H
