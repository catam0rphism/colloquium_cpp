// Copyright 2015 Klimova Kristina 4374
#ifndef ADD_PP_P_CPP
#define ADD_PP_P_CPP

#include "../../structs/struct.h"
#include "../fractional/ADD_QQ_Q.cpp"

polynom ADD_PP_P(const polynom& left, const polynom& right) {
    polynom c_left = left;
    polynom c_right = right;
    polynom result;

    // Вычисляем максимальную степень
    if (c_left.degree() >= c_right.degree())
        int max = c_left.degree();
    else
        int max = c_right.degree();

    // Вычисляем результат
    for (int i = 0; i <= max; i++)
        result[i] = ADD_QQ_Q(c_left[i], c_right[i]);

    return result;
}

#endif  // ADD_PP_P_CPP
