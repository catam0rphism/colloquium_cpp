// Copyright 2015 Черников, Бимбетов 4372
#ifndef ADD_ZZ_Z_CPP
#define ADD_ZZ_Z_CPP

#include "../../structs/struct.h"
#include "../natural/COM_NN_D.cpp"

// Z6 - Сложение целых чисел(результат целое)

integer ADD_ZZ_Z(const integer& a, const integer& b) {
    integer first = a;
    integer second = b;
    integer result;

    if (first.isPositive == second.isPositive) {  // Если знаки равны
        // Знак результата - знак одного из чисел, а модуль - сумма модулей
        result.isPositive = first.isPositive;
        result.module = ADD_NN_N(first.module, second.module);
    } else {  // Если знаки разные
        // Если первое по модулю больше, то знак результата равен знаку первого
        if (COM_NN_D(first.module, second.module) == ordinal::GT) {
            result.isPositive = first.isPositive;
            result.module = SUB_NN_N(first.module, second.module);
        }
        //Если второе по модулю больше, то знак результата равен знаку второго
        if (COM_NN_D(first.module, second.module) == ordinal::LT) {
            result.isPositive = second.isPositive;
            result.module = SUB_NN_N(second.module, first.module);
        }
        // Модуль в обоих случаях равен разнице модулей
        // Иначе результат останется равным 0
    }
    return result;
}

#endif  // ADD_ZZ_Z_CPP
