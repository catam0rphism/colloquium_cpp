// Copyright 2015 Vadim Bertysh
#ifndef GCF_PP_P_CPP
#define GCF_PP_P_CPP

GCF_PP_P(const polynom& left, const polynom& right) {
    polynom divident = left;  // Делимое
    polynom divider = right;  // Делитель
    natural n_zero;  // Нолик

    while (DEG_P_N(divider)            != n_zero &&
           divider[0].numerator.module != n_zero)  {
        // Пока делитель не нулевой полином
        temp = divider;
        divider = MOD_PP_P(divident, divider);
        divident = temp;
    }

    return divident;
}

#endif  // GCF_PP_P_CPP
