// Copyright 2015 Belkin Dmitriy
#ifndef ADD_NN_N_CPP
#define ADD_NN_N_CPP

#include <algorithm>

#include "../../struct.h"

natural ADD_NN_N(natural a, natural b) {
    // Порядок a всегда больше или равен порядку b
    #warning Определить ли a и b как const и использовать временные переменные?
    if (a.order() < b.order()) swap<natural>(&a, &b);

    natural res = a;

    for (int i = 0; i <= b.order(); i++) {
        res.digits[i] += b.digits[i];

        if (res.digits[i] >= 10) {
            res.digits[i] -= 10;

            if (i == res.order()) { res.digits.push_back(1); }
            else { res.digits[i + 1]++; }
        }
    }
}

#endif  // ADD_NN_N_CPP
