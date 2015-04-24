// Copyright 2015 German and Co. Inc. 4371
#ifndef MUL_NN_N_CPP
#define MUL_NN_N_CPP

#include "../../structs/struct.h"

natural MUL_NN_N(const natural &a, const natural &b) {
    natural res = {_0};
    natural fact = b;
    //проходим по всем цифрам второго числа
    for (int i = 0; i < fact.order(); i++) {
        natural mul_res = a;
        //обнуляем переменную, ответсвенную за переполнение
        digit dem = _0;
        //умножаем первое число на i-ю цифру второго числа
        for (int j = 0; j <= mul_res.order(); j++)
            mul_res[j] = mul(mul_res[j], fact[i], dem);
        //удаляем возможные незначащие нули
        mul_res.reduce();
        //смещаем число на i разрядов
        mul_res.orderShift(i);
        //складываем всё в одну переменную
        res = ADD_NN_N(res, mul_res);
    }
    return res;
}

#endif
