// Copyright 2015 Belkin Dmitriy
#include <iostream>

#include "modules/natural/natural.h"
#include "structs/struct.h"
#include "structs/operators.h"

int main(int argc, char const *argv[]) {
    // int counter = 0;

    natural a({ _9, _9, _9, _9, _9 });

    // std::cout << counter++ << std::endl;
    natural b("005000042");
    std::cout << "42?" << std::endl;
    std::cout << b << std::endl;

    // std::cout << 'd' << std::endl;

    // std::cout << counter++ << std::endl;
    natural c = { _9, _9 };
    natural one = { _1 };

    a = { _2, _0, _0 };
    a = SUB_NN_N(c + one, { _9, _9 });

    // std::cout << (1 == _1) << std::endl;

    for (digit d1 = _minDigit; d1 <= _maxDigit; d1 = (digit)(d1 + 1)) {
        for (digit d2 = _minDigit; d2 <= _maxDigit; d2 = (digit)(d2 + 1)) {
            bool b = false;
            std::cout << d1 << " - " << d2 << " <==> " << sub(d1, d2, b) << " ";

            std::cout << b << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << a[-1];

    // std::cout << counter++ << std::endl;
    // for (int i = a.order() - 1 ; i >= 0; i--) {
    //     std::cout << a[i] << " ";
    // }
    return 0;
}
