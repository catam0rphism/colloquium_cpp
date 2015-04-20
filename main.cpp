// Copyright 2015 Belkin Dmitriy
#include <iostream>
#include "modules/natural/natural.h"

int main(int argc, char const *argv[]) {
    // int counter = 0;

    natural a({ _9, _9, _9, _9, _9 });

    // std::cout << counter++ << std::endl;
    natural b = a;

    std::cout << b.digits.size() << std::endl;

    // std::cout << counter++ << std::endl;
    auto c = ADD_1N_N(a);

    // std::cout << counter++ << std::endl;
    for (int i = c.order() - 1 ; i >= 0; i--) {
        std::cout << c.digits[i] << " ";
    }
    return 0;
}
