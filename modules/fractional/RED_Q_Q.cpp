// Copyright 2015 Группа 4373 Александр Николенко, Александр Каламбет 26.04.2015
//
#ifndef RED_Q_Q_CPP
#define RED_Q_Q_CPP

#include "../../structs/struct.h"
#include "../natural/GCF_NN_N.cpp"
#include "../integer/DIV_ZZ_Z.cpp"
#include "../natural/DIV_NN_N.cpp"
#include "../integer/ABS_Z_N.cpp"
#include "../integer/TRANS_N_Z.cpp"


fraction RED_Q_Q(const fraction &RED) {
    natural NOD;
    fraction res;

    // Ищем НОД числителя и знаменателя
    NOD = GCF_NN_N(ABS_Z_N(RED.numerator), RED.denominator);
    // Делим числитель на НОД
    res.numerator.module = DIV_NN_N(RED.numerator.module, NOD);
    res.numerator.isPositive = RED.numerator.isPositive;
    //Делим знаменатель на НОД
    res.denominator = DIV_NN_N(RED.denominator, NOD);

    return res;
}

#endif  // RED_Q_Q_CPP
