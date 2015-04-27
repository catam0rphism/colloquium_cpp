// Copyright 2015 Kudin Dmitriy, Pleshakova Varvara
#ifndef TRANS_N_Z_CPP
#define TRANS_N_Z_CPP

#include "../../structs/struct.h"

//Преобразование натурального в целое
integer TRANS_N_Z(natural a) {
    integer b;
    b.module = a;
    b.isPositive = 1;
    return (b);
}

#endif  // TRANS_N_Z_CPP
