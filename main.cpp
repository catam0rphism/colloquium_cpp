// Copyright 2015 Belkin Dmitriy
#include <iostream>

#include "modules/natural/natural.h"
#include "structs/struct.h"

int main(int argc, char const *argv[]) {
    // int counter = 0;

    natural a({ _9, _9, _9, _9, _9 });

    // std::cout << counter++ << std::endl;
    natural b = { _4, _2 };

    // std::cout << 'd' << std::endl;

    // std::cout << counter++ << std::endl;
    natural c;

    c[0] = _3;
    c[2] = _1;

    // std::cout << counter++ << std::endl;
    for (int i = c.order() - 1 ; i >= 0; i--) {
        std::cout << c[i] << " ";
    }
    return 0;
}
