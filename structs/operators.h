// Copyright 2015 Vadim Bertysh
#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>

#include "./struct.h"
#include "../modules/integer/POZ_Z_D.cpp"

std::ostream& operator<<(std::ostream &os, natural &natural) {
    if (natural.order() == 0) {
        os << 0;
    } else {
        int end = natural.order() - 1;
        while (end >= 0) {
            os << (natural[end]);
            end--;
        }
    }
    return os;
}

std::ostream& operator<<(std::ostream &os, integer &integer) {
    if (integer.module.order() == 0) {
        os << 0;
    } else {
        if (!integer.isPositive) os << "-";
        os << integer.module;
    }
    return os;
}

std::ostream& operator<<(std::ostream &os, fraction &fraction) {
    if (fraction.numerator.module.order() == 0) {
        os << 0;
    } else {
        os << fraction.numerator << '/' << fraction.denominator;
    }
    return os;
}

std::ostream& operator<<(std::ostream &os, polynom &polynom) {
    std::int16_t count = polynom.degree();
    while (count >= 0) {
        if (POZ_Z_D(polynom[count].numerator) != IntegerState::Zero) {
            if (POZ_Z_D(polynom[count].numerator) == IntegerState::Positive)
                os << " + ";
            if (count > 1)
                os << polynom[count] << " x^" << count;
            if (count == 1)
                os << polynom[count] << " x";
            if (count == 0) {
                os << polynom[count];
            }
        }
        count--;
    }
    return os;
}

#endif  // OPERATORS_H
