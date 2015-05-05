// Copyright 2015 Kuptsova Marina 4374
#ifndef DIV_PP_P_CPP
#define DIV_PP_P_CPP

#include "../../structs/struct.h"
#include "../fractional/DIV_QQ_Q.cpp"
#include "./LED_P_Q.cpp"
#include "./SUB_PP_P.cpp"
#include "./MUL_PQ_P.cpp"
#include "./MUL_Pxk_P.cpp"

polynom DIV_PP_P(const polynom& left, const polynom& right) {
    polynom divident = left;  // делимое
    polynom divider = right;  // делитель
    polynom result;  // неполное частное
    int diff = divident.degree() - divider.degree();  // разница степеней
    while (diff >= 0) {
        result[diff] = DIV_QQ_Q(LED_P_Q(divident), LED_P_Q(divider));
        divident = SUB_PP_P(divident, MUL_Pxk_P(
                   MUL_PQ_P(divider, result[diff]), diff))
        divident.reduce();
        diff = divident.degree() - divider.degree();
    }
    return result;
}

#endif  // DIV_PP_P_CPP
