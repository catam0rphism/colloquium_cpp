// Copyright 2015 Rusyaev Sergey, Vasil'eva Maria
#ifndef INV_Z_Z_CPP
#define INV_Z_Z_CPP

#include "../../structs/struct.h"

integer INV_Z_Z(const integer& a)  {
    integer b;  // Инициализация конечного результата
    // Присваиваем результату абсолютную величину данного числа
    b.module = a.module;
    // Присваиваем результату противоположный знак
    if (a.isPositive) b.isPositive = false;
    return b;  // Возвращаем значение результата b
}

#endif  // INV_Z_Z_CPP
