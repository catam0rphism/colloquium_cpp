// Copyright 2015 © Группа 4373, Александр Николенко и Александр Каламбет, 26.04.2015
//
#ifndef RED_Q_Q_CPP
#define RED_Q_Q_CPP

#include "../../structs/struct.h"
#include "../natural/GCF_NN_N.cpp"
#include "../integer/DIV_ZZ_Z.cpp"
#include "../integer/ABS_Z_N.cpp"
#include "../integer/TRANS_Z_N.cpp"


fraction RED_Q_Q(const fraction &RED)
{
	integer NOD;
    fraction RED_C = RED;
	
	NOD = GCF_NN_N(ABS_Z_N(RED.numerator), RED.denominator); //Ищем НОД числителя и знаменатель
	
	RED_C.numerator = DIV_ZZ_Z(ABS_Z_N(RED.numerator), NOD); //Делим числитель на НОД
	RED_C.denominator = TRANS_Z_N(DIV_ZZ_Z(RED.denominator, NOD));//Делим знаменатель на НОД

    return RED_C;
}

#endif //RED_Q_Q_CPP
