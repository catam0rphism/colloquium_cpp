// Copyright 2015 4371
#ifndef DIV_NN_N_CPP
#define DIV_NN_N_CPP

#include "../../structs/struct.h"

#include "./COM_NN_D.cpp"
#include "./DIV_NN_Dk.cpp"
#include "./MUL_NN_N.cpp"
#include "./SUB_NN_N.cpp"
#include "./ADD_NN_N.cpp"

natural DIV_NN_N(const natural& a, const natural& b) {
    natural res;
    natural divident = a;
    natural divider = b;
    natural fact;
    while (COM_NN_D(divident, b) == ordinal::GT) {
        divider = b;
        fact = DIV_NN_Dk(divident, divider);
        divider = MUL_NN_N(divider, fact);
        divident = SUB_NN_N(divident, divider);
        res = ADD_NN_N(res, fact);
    }
    return res;
}

#endif  // DIV_NN_N_CPP
