// Copyright 2015 Belkin Dmitriy
#include <iostream>

#include "modules/natural/natural.h"
#include "structs/struct.h"

int main(int argc, char const *argv[]) {
    // int counter = 0;

    natural a({ _9, _9, _9, _9, _9 });

    // std::cout << counter++ << std::endl;
    natural b( "00000042" );

    // std::cout << 'd' << std::endl;

    // std::cout << counter++ << std::endl;
    natural c = { _9, _9 };
    natural one = { _1 };

    a = ADD_1N_N(a);

    // std::cout << counter++ << std::endl;
    for (int i = a.order() - 1 ; i >= 0; i--) {
        std::cout << a[i] << " ";
    }
    return 0;
}
