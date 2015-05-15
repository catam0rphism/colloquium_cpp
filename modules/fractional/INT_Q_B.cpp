// Copyright 2015 © Группа 4373, Другов Павел и Пынько Антон, 26.04.2015
//
#ifndef INT_Q_B_CPP
#define INT_Q_B_CPP

#include "../../structs/struct.h"
#include "../../structs/operators.h"
#include "./RED_Q_Q.cpp"

bool INT_Q_B(const fraction& fract) {
    fraction F = fract;  // сохранение значения аргумента
    F = RED_Q_Q(F);  // Сокращение дроби
    return (F.denominator == natural(1));  // сравнение знаменателя с единицей и возврат результата
}

#endif  // INT_Q_B_CPP
