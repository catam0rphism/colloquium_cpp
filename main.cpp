// Copyright 2015 Belkin Dmitriy
#include <iostream>

#include "structs/struct.h"
#include "modules/natural/natural.h"
#include "modules/integer/integer.h"
#include "modules/fractional/fractional.h"
#include "modules/polynom/polynom.h"

#include "structs/operators.h"

#define DEBUG_MODE

int main() {
    integer a(-16);
    integer b(4);
    std::cout << DIV_ZZ_Z(a, b);
    string end;
    getline(cin, end);
    return 0;
}
