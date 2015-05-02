// Copyright 2015 Uskova Olga 4374
#ifndef MUL_Pxk_P_CPP
#define MUL_Pxk_P_CPP

#include "../../structs/struct.h"

polinom MUL_Pxk_P(const polinom &value, const unsigned &power) {
    polinom result = value;
    result.degreeShift(power);
    return result;
}

#endif  // MUL_Pxk_P_CPP
