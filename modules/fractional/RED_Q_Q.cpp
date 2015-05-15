// Copyright 2015 Группа 4373 Александр Николенко, Александр Каламбет 26.04.2015
//
#ifndef RED_Q_Q_CPP
#define RED_Q_Q_CPP

#include "../../structs/struct.h"
#include "../natural/GCF_NN_N.cpp"
#include "../integer/DIV_ZZ_Z.cpp"
#include "../integer/ABS_Z_N.cpp"
#include "../integer/TRANS_Z_N.cpp"


fraction RED_Q_Q(const fraction &RED) {
    integer NOD;
    fraction RED_C = RED;

    // Ищем НОД числителя и знаменателя
    NOD = GCF_NN_N(ABS_Z_N(RED.numerator), RED.denominator);

    // Делим числитель на НОД
    RED_C.numerator = DIV_ZZ_Z(ABS_Z_N(RED.numerator), NOD);
    //Делим знаменатель на НОД
    RED_C.denominator = TRANS_Z_N(DIV_ZZ_Z(RED.denominator, NOD));

    return RED_C;
}

#endif  // RED_Q_Q_CPP
