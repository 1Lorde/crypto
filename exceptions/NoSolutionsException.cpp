//
// Created by Vlad Savchuk on 01/10/2020.
//

#include "NoSolutionsException.h"

const char *NoSolutionsException::what() const noexcept {
    return "\nDon`t have any solutions.";
}
