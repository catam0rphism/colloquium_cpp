// Copyright 2015 Belkin Dmitriy
#include <iostream>

#include "structs/struct.h"
#include "modules/natural/natural.h"
#include "modules/integer/integer.h"
#include "modules/fractional/fractional.h"
#include "modules/polynom/polynom.h"

#include "structs/operators.h"

#define DEBUG_MODE

int main(int argc, char const *argv[]) {
    // int counter = 0;

    natural a = natural("123");
    natural b = natural("2");
    natural c = { _2 };
    // auto d = COM_NN_D(a, b);
    // std::cout << int(d) << std::endl;

    // auto d = MUL_Nk_N(c, 2);
    // std::cout << d;
    digit dem = _1;
    // MUL_ND_N(d,be);
    std::cout << mul(_6,_0,dem) << "!!!" << std::endl;
    std::cout << dem << "!!" << std::endl;
	for (int i = 0; i < 1000; i++)
	{
		natural res = DIV_NN_N(a, b);
		std::cout << res << std::endl;
	}
    // std::cout << (a / c) << std::endl;

    // for (natural a = natural(1); a < natural(100); a = ADD_1N_N(a)) {
    //     for(natural b = a; b < natural(100); b = ADD_1N_N(b)) {
    //         auto c = DIV_NN_Dk(a, b);
    //         std::cout << c.first << " " << c.second << std::endl;
    //     }
    // }

    // for (int i = a.order() - 1 ; i >= 0; i--) {
    //     std::cout << a[i] << " ";
    // }
	std::string end;
	getline(std::cin, end);
    return 0;
}
