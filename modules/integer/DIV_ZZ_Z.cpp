// Copyright 2015 Shcherbakov Ivan, Kozlova Alisa
#ifndef DIV_ZZ_Z_CPP
#define DIV_ZZ_Z_CPP
#include "../../structs/struct.h"

// Целочисленное деление двух целых чисел

integer DIV_ZZ_Z(const integer& a, const integer& b)
{
    integer A = a;
    integer B = b;
    integer result;
    if (B.module.order() != 0)  //если делитель НЕ равен нулю
    {
    if (A.isPositive == B.isPositive)  //если знаки равны
        result.isPositive = true;  //частное положительное
    else
        result.isPositive = false;  //частное отрицательное
    result = DIV_NN_N(A.module, B.module);  //обычный остаток, пример: (−17):(−5) = 4 (ост. 3) или 17:5 = 4 (ост. 3)
    if ((((!A.isPositive) && (B.isPositive)) || ((!A.isPositive) && (!B.isPositive))) && (MOD_NN_N(A.module, B.module).order() != 0)) //если первый отрицательный, а второй положительный и не делятся нацело
            result = ADD_1N_N(result.module); //прибавляем единицу      
    return result; //возвращаем ответ
    }
    else //если делитель равен нулю
        throw std::invalid_argument("Da nuuu ti chyo...Na ziro delish"); //ошибочка
}
#endif  // DIV_ZZ_Z_CPP
