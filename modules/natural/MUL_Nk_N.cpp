// Copyright 2015 Vadim Bertysh
#ifndef MUL_NK_N_CPP
#define MUL_NK_N_CPP

#include "../../structs/struct.h"

natural MUL_Nk_N(const natural &value, const unsigned &power) {
    natural result = value;
    result.orderShift(power);
    return result;
}

#endif  // MUL_NK_N_CPP
