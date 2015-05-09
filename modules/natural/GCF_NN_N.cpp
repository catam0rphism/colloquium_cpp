// Copyright 2015 Comrads 4371
#ifndef GCF_NN_N_CPP
#define GCF_NN_N_CPP

#include "../../structs/struct.h"

#include "COM_NN_D.cpp"
#include "MOD_NN_N.cpp"

natural GCF_NN_N(const natural& a, const natural& b) {
    natural divident = a;
    natural divider = b;
    natural some_x;
    while (COM_NN_D(divider, _1) != ordinal::LT) {
        some_x = divider;
        divider = MOD_NN_N(divident, divider);
        divident = some_x;
    }
    return divider;
}

#endif  // GCF_NN_N_CPP
