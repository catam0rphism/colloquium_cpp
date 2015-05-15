// Copyright Солдаткина и Сливенская, группа 4373
// 26.04.2015
#ifndef TRANS_Q_Z_CPP
#define TRANS_Q_Z_CPP

#include <stdexcept>
#include "../../structs/struct.h"
#include "./RED_Q_Q.cpp"

integer TRANS_Q_Z(const fraction& fract) {
	fraction Q = RED_Q_Q(fract);
	natural n_one(1);
    if (Q.denominator != n_one) {
        throw std::invalid_argument("Not an integer");
    }
    //возвращает числитель дроби
    return Q.numerator;
}

#endif  // TRANS_Q_Z_CPP
