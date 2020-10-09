cmake_minimum_required(VERSION 3.17)
project(savchuk)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_SOURCES main.cpp utils/Symbols.cpp models/Number.cpp models/Number.h utils/ModularArithmetic.cpp utils/ModularArithmetic.h exceptions/NotSameModuloException.cpp exceptions/NotSameModuloException.h utils/PrimalityTest.cpp utils/PrimalityTest.h exceptions/NoMultiplicationInverseException.cpp exceptions/NoMultiplicationInverseException.h demo/Demo.cpp demo/Demo.h exceptions/NegativeModuloException.cpp exceptions/NegativeModuloException.h utils/ChineseRemainderTheorem.cpp utils/ChineseRemainderTheorem.h exceptions/NoSolutionsException.cpp exceptions/NoSolutionsException.h)

add_executable(savchuk ${PROJECT_SOURCES})