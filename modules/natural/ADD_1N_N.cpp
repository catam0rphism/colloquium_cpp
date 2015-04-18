// Copyright 2015 Belkin Dmitriy
#ifndef ADD_1N_N_CPP
#define ADD_1N_N_CPP

natural ADD_1N_N(const natural n) {
    natural res = n;
    res.digits[0]++;

    // Сдвигаем разряд при переполнении
    if (res.digits[0] == 10) {
        res.digits[0]-= 10;
        res.digits[1]++;
    }
    return res;
}

#endif  // ADD_1N_N_CPP
