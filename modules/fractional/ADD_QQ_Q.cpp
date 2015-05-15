// copyright 4373 28.04.15 Omeluk, Mokeev
#ifndef ADD_QQ_Q_CPP
#define ADD_QQ_Q_CPP

#include "../../structs/struct.h"
#include "../natural/LCM_NN_N.cpp"
#include "../integer/ADD_ZZ_Z.cpp"
#include "../integer/MUL_ZZ_Z.cpp"
#include "../integer/TRANS_N_Z.cpp"

fraction ADD_QQ_Q(fraction a, fraction b) {
    fraction sum;
    if (b.denominator == a.denominator) {
    // сравнение знаменателей слагаемых
        sum.denominator = b.denominator;
        // если равны, присвоить сумме знаменатель слагаемых
        sum.numerator = ADD_ZZ_Z(a.numerator, b.numerator);
        return sum;
    } else {
        sum.denominator = LCM_NN_N(a.denominator, b.denominator);
        sum.numerator = ADD_ZZ_Z((MUL_ZZ_Z(a.numerator, TRANS_N_Z(sum.denominator / a.denominator))), MUL_ZZ_Z(b.numerator, TRANS_N_Z(sum.denominator / b.denominator)));
        return sum;
    }
}
#endif  // ADD_QQ_Q_CPP
