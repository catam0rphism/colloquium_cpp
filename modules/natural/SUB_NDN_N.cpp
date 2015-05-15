// Copyright 2015 Галеева, Межуева 4371
#ifndef SUB_NDN_N_CPP
#define SUB_NDN_N_CPP

#include <stdexcept>
#include <iostream>

#include "../../structs/struct.h"

#include "MUL_ND_N.cpp"
#include "COM_NN_D.cpp"
#include "SUB_NN_N.cpp"

natural SUB_NDN_N(const natural& a, const natural& b, const digit& n) {
    // natural res = a;
    // natural mul_sub = b;

    // digit fact = n;
    // mul_sub = MUL_ND_N(mul_sub, fact);
    // if (res >= mul_sub) {
    //     auto res_2 = SUB_NN_N(res, mul_sub);
    //     return res_2;
    // } else {
    //     throw std::invalid_argument("Your digit is too big");
    // }
    natural tmp = MUL_ND_N(b, n);
    if(tmp <= a) {
        natural res = SUB_NN_N(a, tmp);        
        return res;
    }
    else throw std::invalid_argument("Result is negative"); // TODO: except
}

#endif  // SUB_NDN_N_CPP
