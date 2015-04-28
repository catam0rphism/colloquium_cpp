// Copyright Charkova Daria, Mirzoeva Marhabo, 4372
#ifndef ABS_Z_N_CPP
#define ABS_Z_N_CPP

#include "../../structs/struct.h"

//Абсолютная величина числа
natural ABS_Z_N(const integer& a) {
    natural b = a.module;  // Присваивает результату абсолютную величину
    return b;  // Возвращает значение
}

#endif  // ABS_Z_N_CPP
