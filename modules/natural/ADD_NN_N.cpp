// Copyright 2015 Belkin Dmitriy
#ifndef ADD_NN_N_CPP
#define ADD_NN_N_CPP

// #include <algorithm>

#include "../../struct.h"

natural ADD_NN_N(const natural& a, const natural& b) {
    natural ltNum, gtNum;  // gtNum имеет больший порядок

    if (a.order() < b.order()) {
        ltNum = a;
        gtNum = b;
    } else {
        ltNum = b;
        gtNum = a;
    }

    natural res(gtNum);

    // Проходим по разрядам числа с меньшим порядком
    for (int i = 0; i < ltNum.order(); i++) {
        res.digits[i] += ltNum.digits[i];

        // Компенсируем переполнение
        if (res.digits[i] >= 10) {
            res.digits[i] -= 10;

            // Если в наибольшем разряде res образовалось число 
            // больше 10, добавляем еще один разряд
            if (i >= res.order()) { res.digits.push_back(1); }
            else { res.digits[i + 1]++; }
        }
    }

    return res;
}

#endif  // ADD_NN_N_CPP
