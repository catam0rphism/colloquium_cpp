// Copyright 2015 Hotamov Kurbon
#ifndef FAC_P_PQ_CPP
#define FAC_P_PQ_CPP

#include "../natural/LCM_NN_N.cpp"
#include "../natural/GCF_NN_N.cpp"
#include "../integer/DIV_ZZ_Z.cpp"
#include "../integer/TRANS_N_Z.cpp"
#include "../integer/TRANS_Z_N.cpp"

polynom FAC_P_PQ(polynom polinom) {
    polynom newpolinom = polinom;
    natural nok = polinom[0].denominator;
    natural nod = TRANS_Z_N(polinom[0].numerator);

    for (int i = 1; i < polinom.degree(); i++) {
        nok = LCM_NN_N(nok, polinom[i].denominator);  // НОК знаменателей
        nod = GCF_NN_N(nod, TRANS_Z_N(polinom[i].numerator));  // НОД числетелей
    }

    for (int i = 0; i < polinom.degree(); i++) {
        newpolinom[i].denominator = 1;
        newpolinom[i].numerator = DIV_ZZ_Z(TRANS_N_Z(nok), TRANS_N_Z(polinom[i].denominator)) * DIV_ZZ_Z(polinom[i].numerator, TRANS_N_Z(nod));  // подсчет коэффициентов нового многочлена
    }

    return newpolinom;
}

#endif  // FAC_P_PQ_CPP
