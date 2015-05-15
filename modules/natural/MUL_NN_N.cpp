// Copyright 2015 German and Co. Inc. 4371
#ifndef MUL_NN_N_CPP
#define MUL_NN_N_CPP

#include "../../structs/struct.h"

#include "ADD_NN_N.cpp"
#include "MUL_ND_N.cpp"
#include "MUL_Nk_N.cpp"

natural MUL_NN_N(const natural &a, const natural &b) {
    natural res = {_0};
    natural fact = b;
    //проходим по всем цифрам второго числа
    for (int i = 0; i < fact.order(); i++) {
        //умножаем первое число на i-ю цифру второго числа
        natural mul_res = MUL_ND_N(a,fact[i]);
        //удаляем возможные незначащие нули
        mul_res.reduce();
        //смещаем число на i разрядов
        mul_res = MUL_Nk_N(mul_res,i);
        //складываем всё в одну переменную
        res = ADD_NN_N(res, mul_res);
    }
    return res;
}

natural natural::operator*(const natural& other) {
    return MUL_NN_N(*this, other);
}

#endif
