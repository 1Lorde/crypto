#ifndef SYMBOLS_DEMO_H
#define SYMBOLS_DEMO_H

#include "ConsoleInteraction.h"

/*
 * Class represents functionality demonstration
 *
 * created by Vlad Savchuk on 25/09/2020.
 */
class Demo {
private:
    static const ConsoleInteraction::Colors demoHeaderColor = ConsoleInteraction::BLUE;

public:
    //demonstrate basic modulus operations with Numbers
    static void demoBasicModOperations();

    //demonstrate Legendre symbol calculation
    static void demoLegendre();

    //demonstrate Jacobi symbol calculation
    static void demoJacobi();

    //demonstrate Solovay-Strassen primality test
    static void demoSolovayStrassenPrimalityTest();

    //demonstrate Solovay-Strassen primality test
    static void demoFermatPrimalityTest();

    //demonstrate Solovay-Strassen primality test
    static void demoLehmannPrimalityTest();

    //demonstrate Chinese Remainder Theorem
    static void demoChineseRemainderTheorem();

    //demonstrate Carmichael Numbers in defined range
    static void demoCarmichaelNumbers();

    //demonstrate big powers using Horner`s method
    static void demoHornerMethod();
    
    static void demoEratostheneSieve();
    static void demoFindNPrimes();
    static void demoFindPrimeBySequenceNumber();
    static void demoFindSequenceNumberByPrime();
    static void demoGoldbachConjecture();
    static void demoLegendreConjecture();
    static void demoPrimeProbability();
    static void demoEllipticCurveCoefficients();
    static void demoEllipticCurvePointsAddition();
};


#endif //SYMBOLS_DEMO_H
