// Copyright 2015 Zhebrun Alexander 4374
#ifndef MOD_PP_P_CPP
#define MOD_PP_P_CPP

#include "../../structs/struct.h"
#include "./SUB_PP_P.cpp"
#include "./MUL_PP_P.cpp"
#include "./DIV_PP_P.cpp"

polynom MOD_PP_P(const polynom& delimoe, const polynom& delitel) {
    polynom a = delimoe;
    polynom b = delitel;
    //Избавление от незначащих разрядов
    a.reduce();
    b.reduce();

    // определяем старшую степень полиномов
    int stpn1 = a.degree();
    int stpn2 = b.degree();
    if (stpn1 < stpn2) {
        polynom ostatok = a;
    } else {
        polynom chastnoe = DIV_PP_P(a, b);
        polynom vichet = MUL_PP_P(b, chastnoe);
        polynom ostatok = SUB_PP_P(a, vichet);
    }
        return ostatok;
}

#endif  // MOD_PP_P_CPP
