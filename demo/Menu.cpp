//
// created by Vlad Savchuk on 24/10/2020.
//

#include "Menu.h"
#include "ConsoleInteraction.h"
#include "Demo.h"

typedef ConsoleInteraction ci;


void Menu::showMainMenu() {
    ci::clearOutput();
    ci::print("****** Demonstration Menu ******\n\n", headerColor);
    ci::print("1.  Basic modular operations\n", entryColor);
    ci::print("2.  Symbols\n", entryColor);
    ci::print("3.  Primality tests\n", entryColor);
    ci::print("4.  Carmichael numbers finding\n", entryColor);
    ci::print("5.  Horner`s method\n", entryColor);
    ci::print("6.  Chinese Remainder Theorem\n", entryColor);
    ci::print("7.  Sieve of Eratosthenes\n", entryColor);
    ci::print("8.  Other utilities\n", entryColor);
    ci::print("0.  Exit\n\n", entryColor);
}

void Menu::handleInputInMainMenu() {
    int choice = -1;

    while (choice != EXIT) {
        showMainMenu();
        try {
            choice = ci::inputInteger();
        }
        catch (...) {
            continue;
        }
        ci::clearOutput();
        switch (choice) {
            case BASIC_MOD_OPERATIONS_DEMO: {
                Demo::demoBasicModOperations();
                break;
            }
            case SYMBOLS_DEMO: {
                handleInputInSymbolsMenu();
                break;
            }
            case PRIMALITY_TESTS_DEMO: {
                handleInputInPrimalityTestsMenu();
                break;
            }
            case CARMICHAEL_NUMBERS_DEMO: {
                Demo::demoCarmichaelNumbers();
                break;
            }
            case HORNER_METHOD_DEMO:{
                Demo::demoHornerMethod();
                break;
            }
            case CHINESE_REMAINDER_THEOREM_DEMO: {
                Demo::demoChineseRemainderTheorem();
                break;
            }
            case SIEVE_OF_ERATOSTHENES_DEMO: {
                Demo::demoEratostheneSieve();
                break;
            }
            case UTILITIES_DEMO: {
                handleInputInUtilityMenu();
                break;
            }
            default:
                break;
        }

        if (choice != PRIMALITY_TESTS_DEMO && choice != SYMBOLS_DEMO && choice != UTILITIES_DEMO)
            ci::pause();
    }

}

void Menu::showSymbolsMenu() {
    ci::clearOutput();
    ci::print("****** Symbols Menu ******\n\n", headerColor);

    ci::print("1. Legendre symbol demo\n", entry2Color);
    ci::print("2. Jacobi symbol demo\n", entry2Color);
    ci::print("0. Back\n\n", entry2Color);
}

void Menu::handleInputInSymbolsMenu() {
    int choice = -1;

    while (choice != RETURN_FROM_SYMBOLS) {
        showSymbolsMenu();
        try {
            choice = ci::inputInteger();
        }
        catch (...) {
            continue;
        }
        ci::clearOutput();
        switch (choice) {
            case LEGENDRE_DEMO: {
                Demo::demoLegendre();
                break;
            }
            case JACOBI_DEMO: {
                Demo::demoJacobi();
                break;
            }

            default:
                break;
        }
        if (choice != RETURN_FROM_SYMBOLS)
            ci::pause();
    }
}

void Menu::showPrimalityTestsMenu() {
    ci::clearOutput();
    ci::print("****** Primality Tests Menu ******\n\n", headerColor);
    ci::print("1. Solovay-Strassen demo\n", entry2Color);
    ci::print("2. Fermat demo\n", entry2Color);
    ci::print("3. Lehmann demo\n", entry2Color);
    ci::print("0. Back\n\n", entry2Color);
}

void Menu::handleInputInPrimalityTestsMenu() {
    int choice = -1;

    while (choice != RETURN_FROM_PRIMALITY_TESTS) {
        showPrimalityTestsMenu();
        try {
            choice = ci::inputInteger();
        }
        catch (...) {
            continue;
        }
        ci::clearOutput();
        switch (choice) {
            case SOLOVAY_STRASSEN: {
                Demo::demoSolovayStrassenPrimalityTest();
                break;
            }
            case FERMAT: {
                Demo::demoFermatPrimalityTest();
                break;
            }
            case LEHMANN: {
                Demo::demoLehmannPrimalityTest();
                break;
            }

            default:
                break;
        }
        if (choice != RETURN_FROM_PRIMALITY_TESTS)
            ci::pause();
    }
}

void Menu::showUtilityMenu() {
    ci::clearOutput();
    ci::print("****** Utility Menu ******\n\n", headerColor);
    ci::print("1. Find prime by sequence number\n", entry2Color);
    ci::print("2. Find sequence number by prime\n", entry2Color);
    ci::print("3. Find N primes\n", entry2Color);
    ci::print("4. Goldbach conjecture\n", entry2Color);
    ci::print("5. Legendre conjecture\n", entry2Color);
    ci::print("6. Prime probability on range\n", entry2Color);
    ci::print("7. Elliptic curve coefficients\n", entry2Color);
    ci::print("0. Back\n\n", entry2Color);
}

void Menu::handleInputInUtilityMenu() {
    int choice = -1;

    while (choice != RETURN_FROM_UTULITIES) {
        showUtilityMenu();
        try {
            choice = ci::inputInteger();
        }
        catch (...) {
            continue;
        }
        ci::clearOutput();
        switch (choice) {
            case PRIME_BY_SEQUENCE_NUMBER_DEMO: {
                Demo::demoFindSequenceNumberByPrime();
                break;
            }
            case SEQUENCE_NUMBER_BY_PRIME_DEMO: {
                Demo::demoFindPrimeBySequenceNumber();
                break;
            }
            case FIND_PRIMES_IN_RANGE_DEMO: {
                Demo::demoFindNPrimes();
                break;
            }
            case GOLDBACH_CONJECTURE_DEMO: {
                Demo::demoGoldbachConjecture();
                break;
            }
            case LEGENDRE_CONJECTURE_DEMO: {
                Demo::demoLegendreConjecture();
                break;
            }
            case PRIME_PROBABILITY_DEMO: {
                Demo::demoPrimeProbability();
                break;
            }
            case ELLIPTIC_CURVE_COEFFICIENTS_DEMO: {
                Demo::demoEllipticCurveCoefficients();
                break;
            }
            default:
                break;
        }

        if (choice != RETURN_FROM_UTULITIES)
            ci::pause();
    }
}

