// Copyright 2015 Belkin Dmitriy
#include <iostream>
#include "modules/natural/natural.h"

int main(int argc, char const *argv[]) {
    enum dig {
        _1 = 1,
        _2 = 2,
        _3 = 3,
        _4 = 4,
        _5 = 5
    };

    std::cout << dig::_4 << std::endl;
    std::cout << (dig)(dig::_4 + dig::_1) << std::endl;
    std::cout << dig::_4 + dig::_3 << std::endl;


    // // int counter = 0;

    // natural a({ 6, 4, 3, 2, 1});

    // // std::cout << counter++ << std::endl;
    // natural b = a;

    // std::cout << b.digits.size() << std::endl;

    // // std::cout << counter++ << std::endl;
    // auto c = ADD_NN_N(a, b);

    // // std::cout << counter++ << std::endl;
    // for (int i = 0; i <= c.order(); i++) {
    //     std::cout << c.digits[i] << " ";
    // }
    return 0;
}
