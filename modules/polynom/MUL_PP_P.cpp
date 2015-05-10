// Copyright 2015 Pozharinskaya Evgenia
#ifndef MUL_PP_P_CPP
#define MUL_PP_P_CPP

#include "../../structs/struct.h"
#include "../integer/MUL_PQ_P.cpp"
#include "../fractional/ADD_QQ_Q.cpp"
#include "./MUL_Pxk_P.cpp"

polynom MUL_PP_P(const polynom& left, const polynom& right) {
    polynom result, temp;

    int stpn1 = left.degree();

    for (int i = 0; i < stpn1; ++i) {
        temp = MUL_PQ_P(left[i], right);
        temp = MUL_Pxk_P(temp, i);
        result += temp;
    }

    return result;
}

#endif  // MUL_PP_P_CPP
