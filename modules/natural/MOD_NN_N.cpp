// Copyright 2015 Comrads 4371
#ifndef MOD_NN_N_CPP
#define MOD_NN_N_CPP

#include "../../structs/struct.h"

natural MOD_NN_N(const natural& a, const natural& b) {
    natural res;
    natural divident = a;
    natural divider = b;
    natural fact;
    fact = DIV_NN_N(divident, divider);
    divider = MUL_NN_N(divider, fact);
    res = SUB_NN_N(divident, divider);
    return res;
}

#endif  // MOD_NN_N_CPP
