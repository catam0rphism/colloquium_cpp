// Copyright 2015 Belkin Dmitriy
#ifndef ADD_1N_N_CPP
#define ADD_1N_N_CPP

#include "../../struct.h"

natural ADD_1N_N(const natural n) {
    natural res = n;
    int lastIndex = n.order() - 1;
    res.digits[lastIndex]++;

    // Сдвигаем разряд при переполнении
    if (res.digits[lastIndex] == 10) {
        res.digits[lastIndex]-= 10;
        res.digits[lastIndex - 1]++;
    }
    return res;
}

#endif  // ADD_1N_N_CPP
