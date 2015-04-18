// Copyright 2015 Belkin Dmitriy
#ifndef ADD_1N_N_CPP
#define ADD_1N_N_CPP

#include "../../struct.h"

natural ADD_1N_N(const natural& n) {
    natural res = n;
    res.digits.back()++;

    // Сдвигаем разряд при переполнении
    if (res.digits.back() == 10) {
        res.digits.back()-= 10;
        *(res.digits.end()--)++;
    }
    return res;
}

#endif  // ADD_1N_N_CPP
