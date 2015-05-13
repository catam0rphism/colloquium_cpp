// Copyright 2015  Elizabeth Karpova
#ifndef DER_P_P_CPP
#define DER_P_P_CPP
#include "../../structs/operators.h"
#include "../../structs/struct.h"
#include "../fractional/MUL_QQ_Q.cpp"
#include "../fractional/ADD_QQ_Q.cpp"

polynom DER_P_P(const polynom& polynom_1) {
    // вспомогательные переменные + степень многочлена
    polynom polynom_2 = polynom_1;
    unsigned size_polynom = polynom_1.degree();
    fraction Number_1(0), Number_2(1);
    polynom_2[size_polynom] = Number_1;  // высшей степени мн-на присваиваем 0

    //дифференцирование многочлена
    for (unsigned p = 0 ; p < size_polynom; ++p) {
        Number_1 = ADD_QQ_Q(Number_1, Number_2);
        polynom_2[p] = MUL_QQ_Q(polynom_1[p+1], Number_1);
    }

    polynom_2.reduce();  // уменьшение степени на 1
    return polynom_2;
}
#endif  // DER_P_P_CPP
