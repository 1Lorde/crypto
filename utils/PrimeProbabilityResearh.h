#ifndef SAVCHUK_PRIMEPROBABILITYRESEARH_H
#define SAVCHUK_PRIMEPROBABILITYRESEARH_H

/*
 *  Class that use to inspect prime probability on different ranges.
 *
 *  created by Vlad Savchuk on 22/10/2020.
 */
class PrimeProbabilityResearh {
public:
    // Залежність кількості простих чисел від номеру числового проміжку довжиною l0 натурального ряду
    static void countPrimesInEachRange(int lengthOfRange, int times);

    // Залежність кількості простих чисел від довжини числового проміжку L (L = m * l0, m є N)
    static void countPrimesInRange(int lengthOfRange, int times);

    // Залежність частоти появи простих чисел від довжини числового проміжку
    static void primeNumberChanceInEachRange(int lengthOfRange, int times);
};


#endif //SAVCHUK_PRIMEPROBABILITYRESEARH_H
