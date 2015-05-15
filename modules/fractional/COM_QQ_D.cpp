// Copyright 2015 Vadim Bertysh
// Каждому блоку по сравнению
#ifndef COM_QQ_D_CPP
#define COM_QQ_D_CPP

#include "../../structs/struct.h"
#include "../natural/LCM_NN_N.cpp"
#include "../integer/MUL_ZZ_Z.cpp"
#include "../integer/COM_ZZ_D.cpp"
#include "../integer/TRANS_N_Z.cpp"

ordinal COM_QQ_D(const fraction& left, const fraction& right) {
    integer lcm = TRANS_N_Z(LCM_NN_N(left.denominator, right.denominator));
    integer numL = MUL_ZZ_Z(left.numerator, lcm);
    integer numR = MUL_ZZ_Z(right.numerator, lcm);
    return COM_ZZ_D(numL, numR);
}

bool operator == (const fraction& left, const fraction& right) {
    return COM_QQ_D(left, right) == ordinal::EQ;
}

#endif  // COM_QQ_D_CPP
