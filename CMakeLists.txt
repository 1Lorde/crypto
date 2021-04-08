cmake_minimum_required(VERSION 3.17)
project(crypto)

set(CMAKE_CXX_STANDARD 14)

include_directories(demo)
include_directories(exceptions)
include_directories(models)
include_directories(utils)

add_executable(crypto
        demo/Demo.cpp
        demo/Demo.h
        exceptions/NegativeModuloException.cpp
        exceptions/NegativeModuloException.h
        exceptions/NoMultiplicationInverseException.cpp
        exceptions/NoMultiplicationInverseException.h
        exceptions/NoSolutionsException.cpp
        exceptions/NoSolutionsException.h
        exceptions/NotSameModuloException.cpp
        exceptions/NotSameModuloException.h
        models/Number.cpp
        models/Number.h
        utils/ChineseRemainderTheorem.cpp
        utils/ChineseRemainderTheorem.h
        utils/ModularArithmetic.cpp
        utils/ModularArithmetic.h
        utils/PrimalityTest.cpp
        utils/PrimalityTest.h
        utils/Symbols.cpp
        utils/Symbols.h
        main.cpp utils/PrimeNumberGenerator.cpp utils/PrimeNumberGenerator.h utils/PrimeNumberUtils.cpp utils/PrimeNumberUtils.h utils/PrimeProbabilityResearh.cpp utils/PrimeProbabilityResearh.h "demo/ConsoleInteraction.cpp" "demo/ConsoleInteraction.h" demo/Menu.cpp demo/Menu.h utils/PrimeNumberGenerator.h utils/EllipticCurveUtils.cpp utils/EllipticCurveUtils.h models/Point.cpp models/Point.h models/EllipticCurve.cpp models/EllipticCurve.h exceptions/NoSpecifiedEllipticCurveException.cpp exceptions/NoSpecifiedEllipticCurveException.h)
