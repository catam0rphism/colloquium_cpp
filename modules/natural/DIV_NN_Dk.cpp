// Copyright 2015 4371 & Belkin Dmitriy
#ifndef DIV_NN_Dk_CPP
#define DIV_NN_Dk_CPP

#define DEBUG_MODE

#include <stdexcept>

#include "../../structs/struct.h"
#include "./MUL_Nk_N.cpp"
#include "./COM_NN_D.cpp"
#include "./ADD_NN_N.cpp"
#include "./SUB_NN_N.cpp"
#include "./ADD_1N_N.cpp"
#include "./NZER_N_B.cpp"

std::pair<digit,std::int16_t> DIV_NN_Dk(const natural& a, const natural& b) {
    if (NZER_N_B(b)) throw std::invalid_argument("Second operand is equal to zero");
    if (b > a) {        
    
        return std::make_pair(_0, 0);
    }

    natural res = a;
    std::int8_t n = a.order() - b.order();

    natural mulB = MUL_Nk_N(b, n);
    natural k;  // ?

    // while (COM_NN_D(res, sub) != ordinal::GT) {
    //     n--;
    //     sub = MUL_Nk_N(b, n);
    // }
    if (a < mulB) {
        n--;
        //#warning n может стать отрицательным =(
        mulB = MUL_Nk_N(b, n);
    }



    

    while (COM_NN_D(res, mulB) != ordinal::LT) {
        res = SUB_NN_N(res, mulB);
        k = ADD_1N_N(k);
    }


    

    // k = MUL_Nk_N(k, n);
    auto result = std::make_pair(k[0], n);


    
    return result;
}

#endif  // DIV_NN_Dk_CPP
