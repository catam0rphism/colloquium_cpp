// Copyright 2015 © Группа 4373, Александр Николенко и Александр Каламбет, 26.04.2015
//
#ifndef RED_Q_Q_CPP
#define RED_Q_Q_CPP

#include "../../structs/struct.h"
#include "RED_Q_Q.cpp"


void RED_Q_Q(fraction &RED)
{
	integer NOD;
	
	NOD = GCF_NN_N(ABS_Z_N(RED.numenator), RED.denominator); //Ищем НОД числителя и знаменатель
	
	RED.numenator = DIV_ZZ_Z(ABS_Z_N(RED.numenator), NOD); //Делим числитель на НОД
	RED.denominator = DIV_ZZ_Z(RED.denominator, NOD);//Делим знаменатель на НОД
}

#endif //RED_Q_Q_CPP
