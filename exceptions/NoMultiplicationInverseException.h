//
// Created by Vlad Savchuk on 25/09/2020.
//

#ifndef SYMBOLS_NOMULTIPLICATIONINVERSEEXCEPTION_H
#define SYMBOLS_NOMULTIPLICATIONINVERSEEXCEPTION_H

#include <exception>
#include <string>

class NoMultiplicationInverseException : public std::exception {
private:
    std::string message;
public:
    explicit NoMultiplicationInverseException(long long element, long long n) {
        message = "\nElement " + std::to_string(element) + "^-1 (mod " + std::to_string(n) + ") don`t have multiplication inverses.";
    };

    const char *what() const noexcept override;
};


#endif //SYMBOLS_NOMULTIPLICATIONINVERSEEXCEPTION_H
