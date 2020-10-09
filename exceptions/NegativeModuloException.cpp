//
// Created by Vlad Savchuk on 26/09/2020.
//

#include "NegativeModuloException.h"


const char *NegativeModuloException::what() const noexcept{
    return message.data();
}