//
// created by Vlad Savchuk on 22/10/2020.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "PrimeProbabilityResearh.h"
#include "PrimalityTest.h"

using namespace std;

void PrimeProbabilityResearh::countPrimesInEachRange(int lengthOfRange, int times) {
    PrimalityTest primalityTest;

#ifdef _WIN_64
    ofstream file("../../../demo/gnuplot/data/countPrimesInEachRange.dat");
#endif
#ifdef linux
    ofstream file("../demo/gnuplot/data/countPrimesInEachRange.dat");
#endif

    file << "#range primes" << endl;

    cout << setw(10) << "Range" << std::setw(20) << "Primes" << endl;
    for (int i = 0; i < times; ++i) {
        int leftBound = i * lengthOfRange;
        int rightBound = leftBound + lengthOfRange;

        file << rightBound << ' ';
        cout << "(" << left << setw(5) << leftBound << setw(1) << "-" << right << setw(5) << rightBound << "):";

        int count = 0;
        for (int j = leftBound; j < rightBound; ++j) {
            if (primalityTest.solovayStrassen(j, 10))
                count++;
        }

        file << count << endl;
        cout << std::setw(15) << count << endl ;
    }
    file.close();

}

void PrimeProbabilityResearh::countPrimesInRange(int lengthOfRange, int times) {
    PrimalityTest primalityTest;

#ifdef _WIN_64
    ofstream file("../../../demo/gnuplot/data/countPrimesInRange.dat");
#endif
#ifdef linux
    ofstream file("../demo/gnuplot/data/countPrimesInRange.dat");
#endif

    file << "#range summary" << endl;

    cout << setw(10) << "Range" << std::setw(20) << "Primes" << std::setw(15) << "Summary" <<endl;
    int sum = 0;
    for (int i = 0; i < times; ++i) {
        int leftBound = i * lengthOfRange;
        int rightBound = leftBound + lengthOfRange;

        file << rightBound << ' ';
        cout << "(" << left << setw(5) << leftBound << setw(1) << "-" << right << setw(5) << rightBound << "):";

        int count = 0;
        for (int j = leftBound; j < rightBound; ++j) {
            if (primalityTest.solovayStrassen(j, 10))
                count++;
        }
        sum += count;
        file << sum << endl;
        cout << std::setw(15) << count << std::setw(15) << sum << endl ;
    }
    file.close();
}

void PrimeProbabilityResearh::primeNumberChanceInEachRange(int lengthOfRange, int times) {
    PrimalityTest primalityTest;

#ifdef _WIN_64
    ofstream file("../../../demo/gnuplot/data/primeNumberChanceInEachRange.dat");
#endif
#ifdef linux
    ofstream file("../demo/gnuplot/data/primeNumberChanceInEachRange.dat");
#endif

    file << "#range chance" << endl;

    cout << setw(7) << "Range" << std::setw(19) << "Primes" << std::setw(15) << "Chance" <<endl;
    int sum = 0;
    for (int i = 0; i < times; ++i) {
        int leftBound = i * lengthOfRange;;
        int rightBound = leftBound + lengthOfRange;

        file << rightBound << ' ';
        cout << "(0 -" << setw(5) << rightBound << "):" ;

        int count = 0;
        double chance = 0;

        for (int j = leftBound; j < rightBound; ++j) {
            if (primalityTest.solovayStrassen(j, 10))
                count++;
        }
        sum += count;
        chance = (double)sum / rightBound;
        file << chance << endl;
        cout << std::setw(15) << sum << std::setw(15) << chance << endl ;
    }
    file.close();
}
