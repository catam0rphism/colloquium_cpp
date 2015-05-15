// Copyright 2015 Belkin Dmitriy
#include <iostream>
#include <string>

#include "structs/struct.h"
#include "modules/natural/natural.h"
#include "modules/integer/integer.h"
#include "modules/fractional/fractional.h"
#include "modules/polynom/polynom.h"

#include "structs/operators.h"

#define DEBUG_MODE

int main() {
    for (int i = 0; i < 20; ++i) {
        integer a("2");
        std::cout << a << std::endl;
    }
    fraction a("2/3");
    fraction b("2/3");
    fraction c("2/3");
    std::cout << a << b << c << std::endl;
    std::cout << int(a == b) << std::endl;
    std::string end;
    getline(std::cin, end);
    return 0;
}
