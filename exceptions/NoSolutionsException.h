//
// Created by Vlad Savchuk on 01/10/2020.
//

#ifndef SYMBOLS_NOSOLUTIONSEXCEPTION_H
#define SYMBOLS_NOSOLUTIONSEXCEPTION_H


#include <exception>

class NoSolutionsException : public std::exception {
public:
    const char *what() const noexcept override;
};


#endif //SYMBOLS_NOSOLUTIONSEXCEPTION_H
