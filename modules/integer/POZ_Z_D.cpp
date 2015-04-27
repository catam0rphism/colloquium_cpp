// Copyright 2015 Rusyaev Sergey, Vasil'eva Maria
#ifndef POZ_Z_D
#define POZ_Z_D

#include "../../structs/struct.h"
#include "../../structs/state.h"

IntegerState POZ_Z_D(const integer& a) {
    short k = 0;
    if (a.order()) {         // если число не равно нулю
        if (a.isPositive)   // определяем его знак
            k = 1;
        else
            k = 2;
    }

    switch (k) {
    case 0:
        return IntegerState::Zero;
        break;
    case 1:
        return IntegerState::Positive;
        break;
    case 2:
        return IntegerState::Negative;
        break;

    default: throw std::invalid_argument("How?");
    }
}

#endif  // POZ_Z_D
