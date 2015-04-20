// Copyright 2015 Belkin Dmitriy
#ifndef ADD_NN_N_CPP
#define ADD_NN_N_CPP

// #include <algorithm>

#include "../../struct.h"
#include "COM_NN_D.cpp"

natural ADD_NN_N(const natural& a, const natural& b) {
    natural ltNum, gtNum;  // gtNum имеет больший порядок

    if (COM_NN_D(a, b) == ordinal::LT) {
        ltNum = a;
        gtNum = b;
    } else {
        ltNum = b;
        gtNum = a;
    }

    natural res(gtNum);

    bool overflowFlag = false;
    // Проходим по разрядам числа с меньшим порядком
    for (int i = 0; i <= ltNum.order(); i++) {
        res.digits[i] = add(res.digits[i], ltNum.digits[i], overflowFlag);
    }

    // прибавили все разряды меньшего к большему,
    // смотрим на переполнение последнего разряда
    int i = ltNum.order();
    while (overflowFlag && i < res.order() - 1) {
        // пока можем, избавляемся от переполнения (для сумм вида "99999 + 1")
        // Обнуляем флаг переполнения чтобы инкремент не увеличил число на два
        overflowFlag = false;
        inc(res.digits[i + 1], overflowFlag);
        i++;
    }
    // Если разряды кончились, а переполнение осталось
    if (overflowFlag && i == res.order() - 1) { res.digits.push_back(_1); } 
    return res;
}

#endif  // ADD_NN_N_CPP
