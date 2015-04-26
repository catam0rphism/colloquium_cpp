// Copyright 2015 Vadim Bertysh
#ifndef DEG_P_N_CPP
#define DEG_P_N_CPP

#include "../../structs/struct.h"

natural DEG_P_N(const polynom &pn) {
    natural result(pn.degree());
    return result;
}

#endif  // DEG_P_N_CPP
