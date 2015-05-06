// Copyright 2015 Balrog
#ifndef MUL_ZZ_Z_CPP
#define MUL_ZZ_Z_CPP
#include "../../structs/struct.h"
#include "../natural/MUL_NN_N.cpp"

integer MUL_ZZ_Z(const integer& left, const integer& right) {
    integer result;
    result.isPositive = (left.isPositive ^ right.isPositive);
    result.module = (MUL_NN_N(left.module, right.module));
    return result;
}

#endif  // MUL_ZZ_Z_CPP
