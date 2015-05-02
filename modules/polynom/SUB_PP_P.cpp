// Copyright 2015 Sereda Irina 4374
#ifndef SUB_PP_P_CPP
#define SUB_PP_P_CPP

#include "../../structs/struct.h"
#include "../fractional/SUB_QQ_Q.cpp"

polynom SUB_PP_P(polynom left, polynom right) {
    polynom result;
    int max;

    int a = left.degree();
    int b = right.degree();

    // Вычисляем максимальную степень
    if (a >= b)
        max = a;
    else
        max = b;

    // Вычисляем результат
    for (int i = 0; i <= max; i++)
        result[i] = SUB_QQ_Q(left[i], right[i]);

    return result;
}

#endif  // SUB_PP_P_CPP
