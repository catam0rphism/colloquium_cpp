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
	natural zero;
	std::cout << zero << std::endl;

	natural one(1);
	std::cout << one << std::endl;

	natural twenty("20");
	std::cout << twenty << std::endl;

	std::string end;
	getline(std::cin, end);
    return 0;
}
