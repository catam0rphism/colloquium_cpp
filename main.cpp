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

    a = { _2, _0, _0 };
    a = SUB_NN_N(c + one, { _9, _9 });

    // std::cout << (1 == _1) << std::endl;

    std::cout << (a == (natural){ _4 });


    // for (int i = a.order() - 1 ; i >= 0; i--) {
    //     std::cout << a[i] << " ";
    // }
    return 0;
}
