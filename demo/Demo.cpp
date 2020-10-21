//
// created by Vlad Savchuk on 25/09/2020.
//

#include "Demo.h"
#include "../utils/PrimalityTest.h"
#include "../utils/ChineseRemainderTheorem.h"
#include "../exceptions/NoSolutionsException.h"
#include <iostream>

#ifdef _WIN_64
#include <conio.h>
#endif

using namespace std;

PrimalityTest primalityTest;
Symbols symbols;
ChineseRemainderTheorem chineseRemainder;


//clear console
void clearOutput() {
#ifdef _WIN64
    system("cls");
#endif

#ifdef linux
    system("clear");
#endif
}

//wait for user input
void pause() {
#ifdef _WIN64
    cout << endl << endl << "Press <ENTER> to continue..";
    getch();
#endif

#ifdef linux
    cout << endl << endl << "Press <ENTER> to continue..";
    int ch = getchar();
    while (ch != '\n')
        ch = getchar();
#endif
}

//handle 32 bit numbers input
int inputInteger(string varName) {
    string value;
    cout << "Enter " << varName << " = ";
    getline(cin, value);
    return stoi(value);
}

//handle 64 bit numbers input
long long inputBigInteger(string varName) {
    string value;
    cout << "Enter " << varName << " = ";
    getline(cin, value);
    return stoll(value);
}

//handle Number object input
Number inputNumber(string varName) {
    long long a, n;
    cout << varName << "{" << endl;
    cout << "\tEnter a = ";
    cin >> a;
    cout << "\tEnter n = ";
    cin >> n;
    cout << "}" << endl;
    return {a, n};
}


//
//functionality demonstration functions
//
void Demo::demoNumbers() {
    cout << endl << "****** Number operations ******" << endl << endl;
    Number num1 = inputNumber("num1");
    Number num2 = inputNumber("num2");

    try {
        cout << "(a+b) mod n = " << num1 + num2 << endl;
        cout << "(a-b) mod n = " << num1 - num2 << endl;
        cout << "(a*b) mod n = " << num1 * num2 << endl;

        Number div = num1 / num2;
        Number inverse = num1.getInverse();
        cout << "(a/b) mod n = " << div << endl;
        cout << "(a^-1) mod n = " << inverse;
    }
    catch (NotSameModuloException &exception) {
        cout << exception.what();
        getchar();
    }
    catch (NoMultiplicationInverseException &exception) {
        cout << exception.what();
        getchar();
    }
}

void Demo::demoLegendre() {
    cout << endl << "****** LEGENDRE symbol - L(a,p) ******" << endl << endl;
    long a = inputBigInteger("a");
    long p = inputBigInteger("p");

    if (primalityTest.solovayStrassenVerbose(p, 20)) {
        long long result = symbols.legendreVerbose(a, p);

        cout << endl << endl << "---------------------------" << endl;
        cout << ">>> ANSWER: L(" << a << "," << p << ") = " << result << "." << endl;
        cout << "x^2 == " << a << " n " << p << " - ";
        if (result == 1) {
            cout << "have solutions.";
        } else if (result == -1) {
            cout << "don`t have solutions.";
        } else if (result == 0) {
            cout << "have solution: x = 0 or multiple of " << a << ".";
        }
        cout << endl << "---------------------------";
    } else {
        cout << "Error, because p isn`t prime. Try to use Jacobi symbol.";
    }
}

void Demo::demoJacobi() {
    cout << endl << "****** JACOBI symbol - J(a,P) ******" << endl << endl;
    long long a = inputBigInteger("a");
    long long P = inputBigInteger("P");

    long long result = symbols.jacobiVerbose(a, P);

    cout << endl << endl << "---------------------------" << endl;
    cout << ">>> ANSWER: J(" << a << "," << P << ") = " << result << "." << endl;
    cout << "x^2 == " << a << " n " << P << " - ";
    if (result == 1) {
        cout << "maybe have solutions.";
    } else if (result == -1) {
        cout << "don`t have solutions.";
    } else if (result == 0) {
        cout << "have solution: x = 0 or multiple of " << a << ".";
    }
    cout << endl << "---------------------------";
}

void Demo::demoSolovayStrassenPrimalityTest() {
    cout << endl << "****** Solovay–Strassen primality test ******" << endl << endl;
    long long n = inputBigInteger("n");
    int k = inputInteger("k");

    cout << endl << "---------------------------" << endl;
    bool result = primalityTest.solovayStrassenVerbose(n, k);

    if (result) {
        cout << ">>> ANSWER: " << n << " maybe prime." << endl;
    } else {
        cout << ">>> ANSWER: " << n << " isn`t prime." << endl;
    }
    cout << "---------------------------";
}

void Demo::demoFermatPrimalityTest() {
    cout << endl << "****** Fermat primality test ******" << endl << endl;
    long long n = inputBigInteger("n");
    int k = inputInteger("k");

    cout << endl << "---------------------------" << endl;
    bool result = primalityTest.fermatVerbose(n, k);

    if (result) {
        cout << ">>> ANSWER: " << n << " maybe prime." << endl;
    } else {
        cout << ">>> ANSWER: " << n << " isn`t prime." << endl;
    }
    cout << "---------------------------";
}

void Demo::demoLehmannPrimalityTest() {
    cout << endl << "****** Lehmann primality test ******" << endl << endl;
    long long n = inputBigInteger("n");
    int k = inputInteger("k");

    cout << endl << "---------------------------" << endl;
    bool result = primalityTest.lehmannVerbose(n, k);

    if (result) {
        cout << ">>> ANSWER: " << n << " maybe prime." << endl;
    } else {
        cout << ">>> ANSWER: " << n << " isn`t prime." << endl;
    }
    cout << "---------------------------";
}

void Demo::demoChineseRemainderTheorem() {
    cout << endl << "****** Chinese Remainder Theorem ******" << endl << endl;
    cout << "x == x1 (mod n1)" << endl;
    cout << "x == x2 (mod n2)" << endl << endl;

    Number num1 = inputNumber("num1");
    Number num2 = inputNumber("num2");

    cout << endl << "Entered system of equations: " << endl << "x == " << num1 << endl << "x == " << num2 << endl;

    try {
        long long partialSolution = chineseRemainder.getPartialSolution(num1, num2);
        cout << endl << "Results:" << endl;
        cout << "* Partial solution: " << partialSolution << endl;
        cout << "* Partial canonical solution: " << chineseRemainder.getPartialCanonicalSolution(num1, num2) << endl;
        cout << "* General solution: " << chineseRemainder.getGeneralSolution(num1, num2) << endl;
        cout << "* General canonical solution: " << chineseRemainder.getGeneralCanonicalSolution(num1, num2);
    }
    catch (NoSolutionsException &exception) {
        cout << exception.what();
        getchar();
    }
}

void Demo::demoCarmichaelNumbers() {
    cout << endl << "****** Carmichael Numbers in range [a,b] ******" << endl << endl;
    long long a = inputBigInteger("a");
    long long b = inputBigInteger("b");
    int k = 20;

    cout << endl << "---------------------------" << endl;
    cout << "Results:" << endl;

    int count = 0;

    for (int i = a; i <= b; ++i) {
        bool fermat = primalityTest.fermat(i, k);
        bool lehmann = primalityTest.lehmann(i, k);

        if (fermat != lehmann){
            cout << i << " " ;
            count++;
        }
    }
    cout << endl << endl << "Find " << count << " numbers, with accuracy (1-2^-" << k << ").";
    cout << endl <<  "---------------------------";
}


//
//interactions with user
//
void Demo::showMainMenu() {
    clearOutput();
    cout << "****** Demonstration Menu ******" << endl << endl;
    cout << "1. Numbers demo" << endl;
    cout << "2. Legendre symbol demo" << endl;
    cout << "3. Jacobi symbol demo" << endl;
    cout << "4. Primality tests demo" << endl;
    cout << "5. Chinese Remainder Theorem demo" << endl;
    cout << "0. Exit" << endl << endl;
}

void Demo::handleInputInMainMenu() {
    int choice = -1;

    while (choice != EXIT) {
        showMainMenu();
        try {
            choice = inputInteger("your choice");
        }
        catch (...) {
            continue;
        }
        clearOutput();
        switch (choice) {
            case NUMBERS_DEMO: {
                demoNumbers();
                break;
            }
            case LEGENDRE_DEMO: {
                demoLegendre();
                break;
            }
            case JACOBI_DEMO: {
                demoJacobi();
                break;
            }
            case PRIMALITY_TESTS_DEMO: {
                handleInputInPrimalityTestsMenu();
                break;
            }
            case CHINESE_REMAINDER_THEOREM_DEMO: {
                demoChineseRemainderTheorem();
                break;
            }

            default:
                break;
        }
        if (choice != PRIMALITY_TESTS_DEMO)
            pause();
    }

}

void Demo::showPrimalityTestsMenu() {
    clearOutput();
    cout << "****** Primality Tests Menu ******" << endl << endl;
    cout << "1. Solovay-Strassen demo" << endl;
    cout << "2. Fermat demo" << endl;
    cout << "3. Lehmann demo" << endl;
    cout << "0. Back" << endl << endl;
}

void Demo::handleInputInPrimalityTestsMenu() {
    int choice = -1;

    while (choice != BACK) {
        showPrimalityTestsMenu();
        try {
            choice = inputInteger("your choice");
        }
        catch (...) {
            continue;
        }
        clearOutput();
        switch (choice) {
            case SOLOVAY_STRASSEN: {
                demoSolovayStrassenPrimalityTest();
                break;
            }
            case FERMAT: {
                demoFermatPrimalityTest();
                break;
            }
            case LEHMANN: {
                demoLehmannPrimalityTest();
                break;
            }

            default:
                break;
        }
        if (choice != BACK)
            pause();
    }
}

void Demo::startDemo() {
    clearOutput();
    cout << "### This program developed by Vlad Savchuk." << endl;
    pause();
    handleInputInMainMenu();
}



