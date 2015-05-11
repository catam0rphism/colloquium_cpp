// Copyright 2015 Belkin Dmitriy
#ifndef ADD_1N_N_CPP
#define ADD_1N_N_CPP

#include "../../structs/struct.h"

natural ADD_1N_N(const natural& n) {
    natural res = n;

    bool overflowFlag = false;
    inc(res[0], overflowFlag);

    // Сдвигаем разряд при переполнении
    int k = 1;
    while (overflowFlag) {
        overflowFlag = false;
        inc(res[k], overflowFlag);
        k++;
    }

    return natural(res);
}

void natural::operator++( int ) {
    digits = ADD_1N_N(*this).digits;
}

#endif  // ADD_1N_N_CPP
