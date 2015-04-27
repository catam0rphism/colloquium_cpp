// Copyright 2015 Черников, Бимбетов 4372
#ifndef SUB_ZZ_Z
#define SUB_ZZ_Z

#include "../../structs/struct.h"

// Z7 - Разность целых чисел(результат целое)

integer SUB_ZZ_Z(const integer& a, const integer& b) {
    integer first = a;
    integer second = b;
    integer result;

    second.isPositive = !second.isPositive;  // Меняем знак второго числа
    result = ADD_ZZ_Z(first, second);  // Складываем получившиеся числа

    return result;
}

#endif  // SUB_ZZ_Z
