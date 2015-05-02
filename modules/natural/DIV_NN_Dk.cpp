// Copyright 2015 4371
#ifndef DIV_NN_Dk_CPP
#define DIV_NN_Dk_CPP

#include <stdexcept>

#include "../../structs/struct.h"
#include "./MUL_Nk_N.cpp"
#include "./COM_NN_D.cpp"
#include "./ADD_NN_N.cpp"
#include "./SUB_NN_N.cpp"
#include "./ADD_1N_N.cpp"
#include "./NZER_N_B.cpp"

natural DIV_NN_Dk(const natural& a, const natural& b) {
    if (NZER_N_B(b)) throw std::invalid_argument("Second operand is equal to zero");

    natural res = a;
    std::int8_t n = a.order() - b.order();

    natural sub = MUL_Nk_N(b, n);
    natural k;  // ?

    // while (COM_NN_D(res, sub) != ordinal::GT) {
    //     n--;
    //     sub = MUL_Nk_N(b, n);
    // }
    if(COM_NN_D(res, sub) != ordinal::GT) {
        n -= 1;
        sub = MUL_Nk_N(b, n);
    }

    while (COM_NN_D(res, sub) != ordinal::LT) {
        res = SUB_NN_N(res, sub);
        k = ADD_1N_N(k);
    }

    k = MUL_Nk_N(k, n);
    return k;
}

#endif  // DIV_NN_Dk_CPP
