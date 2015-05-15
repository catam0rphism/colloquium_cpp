// Copyright 2015 Zubareva Valeria, Myshevskiy Evgeniy

#ifndef MUL_ZZ_Z_CPP
#define MUL_ZZ_Z_CPP

#include "../../structs/struct.h"

//Умножение целых чисел
integer MUL_ZZ_Z(const integer& a, const integer& b) {
    integer result;
    if ((NZER_N_B(a.module)) || (NZER_N_B(b.module)))
        return result;
    result.module = MUL_NN_N(a.module, b.module);
    if (a.isPositive ^ b.isPositive)  // ^ == XOR
        result.isPositive = false;
    return result;
}

integer integer::operator*(const integer& other) {
    return MUL_ZZ_Z(*this, other);
}

#endif  // MUL_ZZ_Z_CPP
