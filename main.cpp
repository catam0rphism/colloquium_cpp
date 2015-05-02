// Copyright 2015 Belkin Dmitriy
#include <iostream>

#include "modules/natural/natural.h"
#include "structs/struct.h"
#include "structs/operators.h"

int main(int argc, char const *argv[]) {
    // int counter = 0;

    natural a = natural("123");
    natural b = natural("2");
    natural c = { _2 };


    std::cout << a << std::endl;
    // natural res = DIV_NN_N(a, b);
    // std::cout << res << std::endl;
    // std::cout << (a / c) << std::endl;

    for (natural a = natural(1); a < natural(100); a = ADD_1N_N(a)) {
        for(natural b = a; b < natural(100); b = ADD_1N_N(b)) {
            auto c = DIV_NN_Dk(a, b);
            std::cout << c.first << " " << c.second << std::endl;
        }
    }

    // for (int i = a.order() - 1 ; i >= 0; i--) {
    //     std::cout << a[i] << " ";
    // }
    return 0;
}
