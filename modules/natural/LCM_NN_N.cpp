// Copyright 2015 Comrads 4371
#ifndef LCM_NN_N_CPP
#define LCM_NN_N_CPP

#include "../../structs/struct.h"

#include "GCF_NN_N.cpp"
#include "MUL_NN_N.cpp"
#include "DIV_NN_N.cpp"

natural LCM_NN_N(const natural& a, const natural& b) {
    natural gcf = GCF_NN_N(a, b);
    natural res = MUL_NN_N(a, b);
    res = DIV_NN_N(res, gcf);
    return res;
}

#endif  // LCM_NN_N_CPP
