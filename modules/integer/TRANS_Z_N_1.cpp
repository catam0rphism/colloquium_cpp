// Copyright 2015 Kudin Dmitriy, Pleshakova Varvara

#ifndef TRANS_Z_N_CPP
#define TRANS_Z_N_CPP

#include "../../structs/struct.h"

//Преобразование целого неотрицательного в натуральное
natural TRANS_Z_N (integer a)
{
	natural b = a.module;
	return (b);
}

#endif // TRANS_Z_N_CPP