// Copyright 2015 Comrads 4371
#ifndef GCF_NN_N_CPP
#define GCF_NN_N_CPP

#include "../../structs/struct.h"
#include "COM_NN_D.cpp"
#include "MOD_NN_N.cpp"

natural GCF_NN_N(const natural& a, const natural& b) {
    // natural divident = a;
    // natural divider = b;
    // natural some_x;
    // while (divider >= _1) {
    //     some_x = divider;
    //     divider = MOD_NN_N(divident, divider);
    //     divident = some_x;
    // }
    // return divider;

    // Just deal with it!
    // (c) Belkin Dmitriy
    return (NZER_N_B(b)) ? a : GCF_NN_N(b, MOD_NN_N(a, b));
}

#endif  // GCF_NN_N_CPP
