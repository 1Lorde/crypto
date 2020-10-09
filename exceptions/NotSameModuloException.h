//
// Created by Vlad Savchuk on 25/9/20.
//


#ifndef SYMBOLS_NOTSAMEMODULOEXCEPTION_H
#define SYMBOLS_NOTSAMEMODULOEXCEPTION_H

#include "exception"

class NotSameModuloException : public std::exception {
public:
    const char *what() const noexcept override;

};


#endif //SYMBOLS_NOTSAMEMODULOEXCEPTION_H
