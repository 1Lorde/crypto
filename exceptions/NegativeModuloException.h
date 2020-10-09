//
// Created by Vlad Savchuk on 26/09/2020.
//

#ifndef SYMBOLS_NEGATIVEMODULOEXCEPTION_H
#define SYMBOLS_NEGATIVEMODULOEXCEPTION_H


#include <exception>
#include <string>

class NegativeModuloException : public std::exception {
private:
    std::string message;
public:
    explicit NegativeModuloException(long long mod) {
        message = "\nModulo N < 1 (N = " + std::to_string(mod) + ").";
    };

    const char *what() const noexcept override;
};


#endif //SYMBOLS_NEGATIVEMODULOEXCEPTION_H
