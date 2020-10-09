#ifndef SYMBOLS_DEMO_H
#define SYMBOLS_DEMO_H

/*
 * Class represents functionality demonstration
 *
 * created by Vlad Savchuk on 25/09/2020.
 */
class Demo {
private:
    //enumeration for CLI menu
    enum MenuEntries {
        EXIT, NUMBERS_DEMO, LEGENDRE_DEMO, JACOBI_DEMO, SOLOVAY_STRASSEN_DEMO, CHINESE_REMAINDER_THEOREM_DEMO
    };

public:
    //method-wrapper for handleInput()
    static void startDemo();

    //show menu with available demos in console
    static void showMenu();

    //handle user choice and call specific demonstration function
    static void handleInput();

    //demonstrate basic modulus operations with Numbers
    static void demoNumbers();

    //demonstrate Legendre symbol calculation
    static void demoLegendre();

    //demonstrate Jacobi symbol calculation
    static void demoJacobi();

    //demonstrate Solovay-Strassen primality test
    static void demoSolovayStrassenPrimalityTest();

    //demonstrate Chinese Remainder Theorem
    static void demoChineseRemainderTheorem();
};


#endif //SYMBOLS_DEMO_H
