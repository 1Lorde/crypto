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
    enum MainMenuEntries {
        EXIT,
        NUMBERS_DEMO,
        SYMBOLS_DEMO,
        PRIMALITY_TESTS_DEMO,
        CARMICHAEL_NUMBERS_DEMO,
        HORNER_METHOD_DEMO,
        CHINESE_REMAINDER_THEOREM_DEMO,
    };

    enum SymbolsMenuEntries {
        RETURN_FROM_SYMBOLS,
        LEGENDRE_DEMO,
        JACOBI_DEMO,
    };

    enum PrimalityTestsMenuEntries {
        RETURN_FROM_PRIMALITY_TESTS,
        SOLOVAY_STRASSEN,
        FERMAT,
        LEHMANN
    };

public:
    //method-wrapper for handleInputInMainMenu()
    static void startDemo();

    //show Main menu with available demos in console
    static void showMainMenu();

    //show Symbols menu with available demos in console
    static void showSymbolsMenu();

    //show Primality tests menu with available demos in console
    static void showPrimalityTestsMenu();

    //handle user choice in Main menu and call specific demonstration function
    static void handleInputInMainMenu();

    //handle user choice in Symbols menu and call specific demonstration function
    static void handleInputInSymbolsMenu();

    //handle user choice in Primality tests menu and call specific demonstration function
    static void handleInputInPrimalityTestsMenu();

    //demonstrate basic modulus operations with Numbers
    static void demoNumbers();

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

    //find Carmichael Numbers in defined range
    static void demoCarmichaelNumbers();

    //find big powers using Horner`s method
    static void demoHornerMethod();
};


#endif //SYMBOLS_DEMO_H
