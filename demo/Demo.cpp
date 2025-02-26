//
// created by Vlad Savchuk on 25/09/2020.
//

#include "Demo.h"
#include "../utils/PrimalityTest.h"
#include "../utils/ChineseRemainderTheorem.h"
#include "../exceptions/NoSolutionsException.h"
#include "ConsoleInteraction.h"
#include <iostream>
#include <ctime>
#include <PrimeNumberUtils.h>
#include <PrimeProbabilityResearh.h>
#include <PrimeNumberGenerator.h>
#include <EllipticCurveUtils.h>
#include <Point.h>

#ifdef _WIN32
#include <conio.h>
#endif

using namespace std;
typedef ConsoleInteraction ci;

PrimalityTest primalityTest;
Symbols symbols;
ChineseRemainderTheorem chineseRemainder;
EllipticCurveUtils ellipticCurveUtils;

//
//functionality demonstration functions
//
void Demo::demoBasicModOperations() {
    ci::print("****** ");
    ci::print("Number operations", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    Number num1 = ci::inputNumber("num1");
    Number num2 = ci::inputNumber("num2");

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
    ci::print("****** ");
    ci::print("LEGENDRE symbol - L(a,p)", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    long a = ci::inputBigInteger("a");
    long p = ci::inputBigInteger("p");

    if (primalityTest.solovayStrassenVerbose(p, 20)) {
        long long result = symbols.legendreVerbose(a, p);

        cout << endl << endl << "---------------------------" << endl;
        cout << ">>> ANSWER: L(" << a << "," << p << ") = " << result << "." << endl;
        cout << "x^2 == " << a << " mod " << p << " - ";
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
    ci::print("****** ");
    ci::print("JACOBI symbol - J(a,P)", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    long long a = ci::inputBigInteger("a");
    long long P = ci::inputBigInteger("P");

    long long result = symbols.jacobiVerbose(a, P);

    cout << endl << endl << "---------------------------" << endl;
    cout << ">>> ANSWER: J(" << a << "," << P << ") = " << result << "." << endl;
    cout << "x^2 == " << a << " mod " << P << " - ";
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
    ci::print("****** ");
    ci::print("Solovay–Strassen primality test", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    long long n = ci::inputBigInteger("n");
    int k = ci::inputInteger("k");

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
    ci::print("****** ");
    ci::print("Fermat primality test", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    long long n = ci::inputBigInteger("n");
    int k = ci::inputInteger("k");

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
    ci::print("****** ");
    ci::print("Lehmann primality test", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    long long n = ci::inputBigInteger("n");
    int k = ci::inputInteger("k");

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
    ci::print("****** ");
    ci::print("Chinese Remainder Theorem", Demo::demoHeaderColor);
    ci::print(" ******\n\n");
    ci::print("   || Chinese remainder theorem states that if one knows the remainders\n"
              "   || of the Euclidean division of an integer n by several integers,\n"
              "   || then one can determine uniquely the remainder of the division of n\n"
              "   || by the product of these integers, under the condition that the divisors\n"
              "   || are pairwise coprime.\n\n");

    cout << "x == x1 (mod n1)" << endl;
    cout << "x == x2 (mod n2)" << endl << endl;

    Number num1 = ci::inputNumber("num1");
    Number num2 = ci::inputNumber("num2");

    cout << endl << "Entered system of equations: " << endl << "x == " << num1 << endl << "x == " << num2 << endl;

    try {
        long long partialSolution = chineseRemainder.getPartialSolution(num1, num2);
        cout << endl << "Results:" << endl;
        cout << "* Partial solution: " << partialSolution << endl;
        cout << "* Partial canonical solution: " << chineseRemainder.getPartialCanonicalSolution(num1, num2) << endl;
        cout << "* General solution: " << chineseRemainder.getGeneralSolution(num1, num2) << endl;
        cout << "* General canonical solution: " << chineseRemainder.getGeneralCanonicalSolution(num1, num2);
        getchar();
    }
    catch (NoSolutionsException &exception) {
        cout << exception.what();
        getchar();
    }
}

void Demo::demoCarmichaelNumbers() {
    ci::print("****** ");
    ci::print("Carmichael Numbers in range [a,b]", Demo::demoHeaderColor);
    ci::print(" ******\n\n");
    ci::print("   || Carmichael number is a composite number n which satisfies\n"
              "   || the modular arithmetic congruence relation: b^(n-1) == 1 (mod n)\n"
              "   || for all integers b which are relatively prime to n.\n"
              "   || Carmichael numbers are also called Fermat pseudoprimes or absolute Fermat pseudoprimes.\n\n");

    cout << endl << " !!! NOTICE: For range with length greater than 10^6 this algorithm use a lot of time."
         << endl;
    cout << endl << "-----------------------------------------------" << endl << endl;

    long long a = ci::inputBigInteger("a");
    long long b = ci::inputBigInteger("b");
    int k = 20;

    cout << endl << "---------------------------" << endl;
    cout << "Results:" << endl;

    int count = 0;
    time_t start, end; // initialize timers

    time(&start); // start timer
    for (long long i = a; i <= b; ++i) {
        bool fermat = primalityTest.fermat(i, k);
        bool lehmann = primalityTest.lehmann(i, k);

        if (fermat != lehmann) {
            cout << i << " ";
            count++;
        }
    }
    time(&end); // end timer
    cout << endl << endl << "Found " << count << " numbers, with accuracy (1-2^-" << k << ").";
    cout << endl << "---------------------------";

    double seconds = difftime(end, start);
    cout << endl << endl << "[ Used time: " << seconds << " second(s) ]" << endl;
}

void Demo::demoHornerMethod() {
    ci::print("****** ");
    ci::print("Horner`s method", Demo::demoHeaderColor);
    ci::print(" ******\n\n");
    cout << "Enter x^y mod n." << endl << endl;

    long long x = ci::inputBigInteger("x");
    long long y = ci::inputBigInteger("y");
    long long n = ci::inputBigInteger("n");

    cout << endl << "---------------------------" << endl;
    long long result = ModularArithmetic::hornerPowVerbose(x, y, n);

    cout << endl << endl << endl << ">>> ANSWER: " << x << "^" << y << " mod " << n << " = " << result << "." << endl;
    cout << "---------------------------";
}

void Demo::demoEratostheneSieve() {
    ci::print("****** ");
    ci::print("Sieve of Eratosthenes", Demo::demoHeaderColor);
    ci::print(" ******\n\n");
    ci::print("   || Sieve of Eratosthenes is an ancient algorithm for finding\n"
              "   || all prime numbers up to any given limit.\n\n");

    long long n = ci::inputBigInteger("range");

    cout << endl << "---------------------------" << endl;
    cout << "Primes:" << endl;
    for (long long i : PrimeNumberGenerator::eratosthenesSieve(n))
        cout << i << " ";

    cout << endl << "---------------------------";
}

void Demo::demoFindSequenceNumberByPrime() {
    ci::print("****** ");
    ci::print("Prime`s sequence number", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    long long n = ci::inputBigInteger("prime");

    if (!primalityTest.solovayStrassen(n, 20)) {
        cout << "Entered number isn`t prime!";
        return;
    }

    cout << endl << "---------------------------" << endl;
    cout << "Sequence number: ";
    cout << PrimeNumberUtils::getSequenceNumberOfPrime(n) << endl;

    cout << endl << "---------------------------";
}

void Demo::demoFindPrimeBySequenceNumber() {
    ci::print("****** ");
    ci::print("Find prime by sequence number demo", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    long long n = ci::inputBigInteger("sequence number");

    cout << endl << "---------------------------" << endl;
    cout << "Prime: " << PrimeNumberUtils::getPrimeBySeqNumber(n);
    cout << endl << "---------------------------";

}

void Demo::demoFindNPrimes() {
    ci::print("****** ");
    ci::print("Find N prime numbers demo", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    long long n = ci::inputBigInteger("N");

    cout << endl << "---------------------------" << endl;
    cout << "Primes: " << endl;
    for (long long i : PrimeNumberUtils::findNPrimes(n)) {
        cout << i << " ";
    }
    cout << endl << "---------------------------";
}

void Demo::demoGoldbachConjecture() {
    ci::print("****** ");
    ci::print("Goldbach Conjecture demo", Demo::demoHeaderColor);
    ci::print(" ******\n\n");
    ci::print("   || Goldbach conjecture states that every even whole number greater than 2\n"
              "   || is the sum of two prime numbers.\n\n");

    long long n = ci::inputBigInteger("number");

    if (n % 2 || n < 2) {
        cout << "Entered number not even!";
        return;
    }


    cout << endl << "---------------------------" << endl;
    cout << "Result: " << n << " = ";
    for (long long i : PrimeNumberUtils::goldbachConjecture(n)) {
        cout << i << " + ";
    }
    cout << "\b\b" << " " << endl;
    cout << endl << "---------------------------";
}

void Demo::demoLegendreConjecture() {
    ci::print("****** ");
    ci::print("Legendre Conjecture demo", Demo::demoHeaderColor);
    ci::print(" ******\n\n");
    ci::print("   || Legendre's conjecture states that there is a prime number\n"
              "   || between n2 and (n + 1)^2 for every positive integer n.\n\n");

    long long n = ci::inputBigInteger("n");

    cout << endl << "---------------------------" << endl;
    cout << "Result: " << endl;
    for (long long i : PrimeNumberUtils::legendreConjecture(n)) {
        cout << i << " ";
    }
    cout << endl << "---------------------------";
}

void Demo::demoPrimeProbability() {
    ci::print("****** ");
    ci::print("Prime probability on range demo", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    int l0 = ci::inputInteger("length of each range");
    int amount = ci::inputInteger("amount");

    cout << endl << endl << "------------------------------------------------------" << endl;
    PrimeProbabilityResearh::countPrimesInEachRange(l0, amount);
    cout << endl << endl << "------------------------------------------------------" << endl;

    PrimeProbabilityResearh::countPrimesInRange(l0, amount);
    cout << endl << endl << "------------------------------------------------------" << endl;

    PrimeProbabilityResearh::primeNumberChanceInEachRange(l0, amount);
    cout << endl << "------------------------------------------------------";
}

void Demo::demoEllipticCurveCoefficients() {
    ci::print("****** ");
    ci::print("Elliptic curve coefficients demo", Demo::demoHeaderColor);
    ci::print(" ******\n\n");
    ci::print("   || Finds elliptic curve coefficients, which has prime\n"
              "   || number of points.\n\n");

    ci::print("y^2 = x^3 + Ax + B.\n\n");

    int p = ci::inputInteger("p");
    list<EllipticCurve> curves = ellipticCurveUtils.findCoefficientsWithPrimeCountOfPoints(p);

    for (auto curve : curves) {
        cout << "For A: " << curve.getA() << " and B: " << curve.getB() << "  ==>  n: " << curve.getP() << "\n";
    }
}

void Demo::demoEllipticCurvePointsAddition() {
    ci::print("****** ");
    ci::print("Elliptic curve`s points addition demo", Demo::demoHeaderColor);
    ci::print(" ******\n\n");

    ci::print("y^2 = x^3 + Ax + B.\n");

    int A = ci::inputInteger("A");
    int B = ci::inputInteger("B");
    int p = ci::inputInteger("p");

    ci::print("\nP = (Xp, Yp).\n");
    int Xp = ci::inputInteger("Xp");
    int Yp = ci::inputInteger("Yp");

    ci::print("\nQ = (Xq, Yq).\n");
    int Xq = ci::inputInteger("Xq");
    int Yq = ci::inputInteger("Yq");

    EllipticCurve curve = EllipticCurve(A, B, p);
    Point P1 = Point("P", Xp, Yp, &curve);
    Point P2 = Point("P", Xq, Yq, &curve);

    ci::print("\n\nRESULT:\n");

    if (P1.isOnEllipticCurve(curve)) {
        if (P2.isOnEllipticCurve(curve)) {
            Point R2 = P1 + P2;
            cout << endl << R2;

            if (R2.isOnEllipticCurve(curve)) {
                cout << endl << "R is on elliptic curve " << curve << ".";
            } else {
                cout << endl << "R is not on elliptic curve " << curve << ".";
            }
        } else {
            cout << endl << "P2 is not on elliptic curve " << curve << ".";
        }
    } else {
        cout << endl << "P1 is not on elliptic curve " << curve << ".";
    }
}