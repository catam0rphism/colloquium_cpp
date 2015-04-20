// Copyright 2015 Belkin Dmitriy
#ifndef ADD_1N_N_CPP
#define ADD_1N_N_CPP

#include "../../struct.h"

natural ADD_1N_N(const natural& n) {
    natural res = n;
    bool overflowFlag = false;
    inc(res.digits.back(),overflowFlag);

    // Сдвигаем разряд при переполнении
    k = 1;
    while (overflowFlag && k != res.digit.order()) {
        inc(*(res.digits.end() - k), overflowFlag);
        k++;
    }
    return res;
}

#endif  // ADD_1N_N_CPP
