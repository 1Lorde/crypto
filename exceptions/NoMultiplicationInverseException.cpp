//
// Created by Vlad Savchuk on 25/09/2020.
//

#include "NoMultiplicationInverseException.h"

const char *NoMultiplicationInverseException::what() const noexcept{
    return message.data();
}


