// Copyright 2015 Галеева, Межуева 4371
#ifndef SUB_NDN_N_CPP
#define SUB_NDN_N_CPP

#include <stdexcept>

#include "../../structs/struct.h"

#include "MUL_ND_N.cpp"
#include "COM_NN_D.cpp"
#include "SUB_NN_N.cpp"

natural SUB_NDN_N(const natural& a, const natural& b, const digit& n) {
    natural res = a;
    natural mul_sub = b;

    digit fact = n;
    mul_sub = MUL_ND_N(mul_sub, fact);
    if (COM_NN_D(res, mul_sub) != ordinal::LT) {
        auto res_2 = SUB_NN_N(res, mul_sub);
        return res_2;
    } else {
        throw std::invalid_argument("Your digit is too big");
    }
}

#endif  // SUB_NDN_N_CPP
