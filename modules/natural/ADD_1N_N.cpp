// Copyright 2015 Belkin Dmitriy
#ifndef ADD_1N_N_CPP
#define ADD_1N_N_CPP

#include "../../struct.h"

natural ADD_1N_N(const natural& n) {
    natural res = n;

    bool overflowFlag = false;
    inc(res.digits[0], overflowFlag);

    // Сдвигаем разряд при переполнении
    int k = 1;
    while (overflowFlag && k <= res.order() - 1) {
        overflowFlag = false;
        inc(res.digits[k], overflowFlag);
        k++;
    }

    if (overflowFlag) { res.digits.push_back(_1); }
    return res;
}

#endif  // ADD_1N_N_CPP
