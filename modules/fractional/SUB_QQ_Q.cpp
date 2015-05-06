// Copyright 2015 © 4373 Group, Golovnia Ian, Popova Ekaterina.
#ifndef SUB_QQ_Q_CPP
#define SUB_QQ_Q_CPP

#include "../../structs/struct.h"
#include "../natural/LCM_NN_N.cpp"   // НОК
#include "../natural/DIV_NN_N.cpp"   // Деление
#include "../integer/MUL_ZZ_Z.cpp"   // Умножение
#include "../integer/SUB_ZZ_Z.cpp"   // Вычитание
#include "../integer/TRANS_N_Z.cpp"  // Натуральное->целое
#include "./RED_Q_Q.cpp"    // Сокращение

fraction SUB_QQ_Q(fraction &fract_1, fraction &fract_2)
{
    // Ищем НОK знаменателей
    natural NOK = LCM_NN_N(fract_1.denominator, fract_2.denominator); 
    
    // Нахождение множителей числителей
    natural K1 = DIV_NN_N(NOK, fract_1.denominator);
    integer J1 = TRANS_N_Z(K1);
    natural K2 = DIV_NN_N(NOK, fract_2.denominator);
    integer J2 = TRANS_N_Z(K2);
    
    // Умножение
    integer L1 = MUL_ZZ_Z(fract_1.numerator, J1);  
    integer L2 = MUL_ZZ_Z(fract_2.numerator, J2);
    
    // Вычитание, построение итоговой дроби
    fraction result;
    result.numerator = SUB_ZZ_Z(L1, L2);
    result.denominator = NOK;
    return result;
}

#endif  //SUB_QQ_Q_CPP
