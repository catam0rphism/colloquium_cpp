// Copyright 2015 Comrads 4371
#ifndef DIV_NN_N_CPP
#define DIV_NN_N_CPP

#include <stdexcept>
#include <iostream>

#include "../../structs/struct.h"
#include "../../structs/operators.h"
#include "./COM_NN_D.cpp"
#include "./DIV_NN_Dk.cpp"
#include "./MUL_NN_N.cpp"
#include "./MUL_ND_N.cpp"
#include "./SUB_NDN_N.cpp"
#include "./ADD_NN_N.cpp"
#include "./NZER_N_B.cpp"

#define DEBUG_MODE

natural DIV_NN_N(const natural& a, const natural& b) {
    if (NZER_N_B(b)) throw std::invalid_argument("Your divider is equal to zero");
    // // natural res = natural();
    // // natural divident = a;
    // // natural divider = b;
    // // natural fact = natural();
    // // while (COM_NN_D(divident, b) == ordinal::GT) {
    // //     divider = b;
    // //     fact = DIV_NN_Dk(divident, divider);
    // //     divider = MUL_NN_N(divider, fact);
    // //     divident = SUB_NN_N(divident, divider);
    // //     res = ADD_NN_N(res, fact);
    // // }
    // // return res;

    natural res;
    natural _a = a;

    while (_a >= b) {
        auto k = DIV_NN_Dk(_a, b);

        // std::cout << int(k.first) << std::endl;
        #ifdef DEBUG_MODE
        std::cout << "DIV_NN_Dk worked" << std::endl;
        #endif  // DEBUG_MODE
        // std::cout << _a << std::endl;
        // natural _b = b;
        // std::cout << _b << std::endl;
        auto sub = MUL_Nk_N(b, k.second);
        natural c = SUB_NDN_N(_a, sub, k.first);
        _a = c;

// #ifdef DEBUG_MODE
// std::cout << "Calling MUL_Nk_N" << std::endl;
// #endif  // DEBUG_MODE

#ifdef DEBUG_MODE
auto temp = MUL_Nk_N(natural({ k.first }), k.second);
std::cout << "Shifted to " <<  temp << std::endl;
#endif  // DEBUG_MODE
    auto res_t = res;
    res = res_t + temp;

    #ifdef DEBUG_MODE
    std::cout << "res is " << res << std::endl;
    #endif  // DEBUG_MODE
    }

    #ifdef DEBUG_MODE
    std::cout << "DIV_NN_N worked" << std::endl;
    #endif  // DEBUG_MODE


    return res;
}

natural natural::operator/(const natural& other) {
    return DIV_NN_N(*this, other);
}

#endif  // DIV_NN_N_CPP
