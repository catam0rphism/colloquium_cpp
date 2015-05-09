// Copyright 2015 German and Co. Inc. 4371
#ifndef MUL_ND_N_CPP
#define MUL_ND_N_CPP

#include "../../structs/struct.h"

natural MUL_ND_N(const natural &a, const digit &n) {
    // учитываем случаи, когда n = 0 и n = 1
    natural a_c = a;
    switch (n) {
    case _0:
        return natural({_0});
        break;
    case _1:
        return a;
        break;
    default:

        natural res = a;
        digit dem = _0;
        digit fact = n;
        // умножаем каждую цифру числа на n методом mul
        // переполнение самого старшего разряда учитывается
        for (int i = 0; i <= res.order(); i++) {
            auto temp = res[i];
            res[i] = mul(temp, fact, dem);
        }
        // удаляем возможные незначащие нули
        res.reduce();
        return res;
    }
}

natural natural::operator*(const digit& other) {
    return MUL_ND_N(*this, other);
}

#endif
