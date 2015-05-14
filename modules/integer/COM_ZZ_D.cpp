// Copyright 2015 Vadim Bertysh
// Да будет работа с целыми проще
#ifndef COM_ZZ_D_CPP
#define COM_ZZ_D_CPP

#include "../../structs/struct.h"
#include "../natural/COM_NN_D.cpp"
#include "./POZ_Z_D.cpp"

ordinal COM_ZZ_D(const integer& left, const integer& right) {
    auto leftState  = POZ_Z_D(left);
    auto rightState = POZ_Z_D(right);
    // Ноль
    if (leftState  == IntegerState::Zero &&
        rightState == IntegerState::Zero) return ordinal::EQ;
    // Разные знаки
    // TODO(Vadim Bertysh): проверить работоспособность
    if (leftState != rightState) return static_cast<ordinal>(leftState);
    // Оба отрицательные
    if (leftState == IntegerState::Negative) return COM_NN_D(right.module, left.module);
    // Оба положительные
    if (leftState == IntegerState::Positive) return COM_NN_D(left.module, right.module);
}

bool operator == (const integer& left, const integer& right) {
    return COM_ZZ_D(left, right) == ordinal::EQ;
}

#endif // COM_ZZ_D_CPP
