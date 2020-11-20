//
// created by Vlad Savchuk on 24/10/2020.
//

#ifndef SAVCHUK_MENU_H
#define SAVCHUK_MENU_H


#include "ConsoleInteraction.h"

class Menu {
private:
    //enumeration for CLI menu
    enum MainMenuEntries {
        EXIT,
        BASIC_MOD_OPERATIONS_DEMO,
        SYMBOLS_DEMO,
        PRIMALITY_TESTS_DEMO,
        CARMICHAEL_NUMBERS_DEMO,
        HORNER_METHOD_DEMO,
        CHINESE_REMAINDER_THEOREM_DEMO,
        SIEVE_OF_ERATOSTHENES_DEMO,
        UTILITIES_DEMO
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

    enum UtilityMenuEntries {
        RETURN_FROM_UTULITIES,
        SEQUENCE_NUMBER_BY_PRIME_DEMO,
        PRIME_BY_SEQUENCE_NUMBER_DEMO,
        FIND_PRIMES_IN_RANGE_DEMO,
        GOLDBACH_CONJECTURE_DEMO,
        LEGENDRE_CONJECTURE_DEMO,
        PRIME_PROBABILITY_DEMO,
        ELLIPTIC_CURVE_COEFFICIENTS_DEMO
    };

    static const ConsoleInteraction::Colors headerColor = ConsoleInteraction::GREY;
    static const ConsoleInteraction::Colors entryColor = ConsoleInteraction::YELLOW;
    static const ConsoleInteraction::Colors entry2Color = ConsoleInteraction::YELLOW;

public:
    //show Main menu with available demos in console
    static void showMainMenu();

    //show Symbols menu with available demos in console
    static void showSymbolsMenu();

    //show Primality tests menu with available demos in console
    static void showPrimalityTestsMenu();

    //show Utility menu with available demos in console
    static void showUtilityMenu();

    //handle user choice in Main menu and call specific demonstration function
    static void handleInputInMainMenu();

    //handle user choice in Symbols menu and call specific demonstration function
    static void handleInputInSymbolsMenu();

    //handle user choice in Primality tests menu and call specific demonstration function
    static void handleInputInPrimalityTestsMenu();

    //handle user choice in Utility menu and call specific demonstration function
    static void handleInputInUtilityMenu();
};


#endif //SAVCHUK_MENU_H
