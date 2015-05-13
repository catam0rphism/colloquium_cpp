// Copyright 2015 Shcherbakov Ivan, Kozlova Alisa
#ifndef MOD_ZZ_Z_CPP
#define MOD_ZZ_Z_CPP

#include "../../structs/struct.h"

#include "../natural/COM_NN_D.cpp"
#include "../natural/NZER_N_B.cpp"

// Целочисленное деление двух целых чисел

integer MOD_ZZ_Z(const integer& a, const integer& b)
{
    integer A = a;
    integer B = b;
    integer result;
    result.isPositive = true;  //всегда положительный
    if (NZER_N_B(B.module))  //если делитель НЕ равен нулю
    {
        result.module = MOD_NN_N(A.module, B.module);  //просто находим остаток
            if (!(A.isPositive) && NZER_N_B(result.module))  //если делимое положительно и делится с остатком
                result.module = B.module - MOD_NN_N(A.module, B.module);
                //необычный остаток, пример:(−17)/(−5)=4(ост.3) или (−7)/2=−4(ост.1)
        return result;  //возвращаем ответ
    } else {  //если делитель равен нулю
        throw std::invalid_argument("Da nuuu ti chyo...Na ziro delish"); //ошибочка
    }
}

#endif  // MOD_ZZ_Z_CPP
