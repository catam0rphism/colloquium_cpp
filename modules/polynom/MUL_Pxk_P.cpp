// Copyright 2015 Uskova Olga 4374
#ifndef MUL_Pxk_P_CPP
#define MUL_Pxk_P_CPP

#include "../../structs/struct.h"

polynom MUL_Pxk_P(const polynom &value, const unsigned &power) {
    polynom result = value;
    result.degreeShift(power);
    return result;
}

#endif  // MUL_Pxk_P_CPP
