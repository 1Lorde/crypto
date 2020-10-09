//
// Created by Vlad Savchuk on 25/9/20.
//

#include "NotSameModuloException.h"

const char *NotSameModuloException::what() const noexcept {
    return "\nModulo N not same for Number objects.";
}
