// Copyright 2015 Жилин Н., Середнюк А. 
#ifndef DIV_QQ_Q_CPP
#define DIV_QQ_Q_CPP

#include "../../structs/struct.h"
#include "MUL_ZZ_Z.cpp"

fraction DIV_QQ_Q(const fraction &a, const fraction &b)
{
	fraction c;
	integer aden, bden;
	//приводим знаменатель первой дроби к виду целого числа:
	aden.module = a.denominator;
	aden.isPositive = 1; 
	//приводим знаменатель второй дроби к виду целого числа:
	bden.module = b.denominator;
	bden.isPositive = 1;
	c.numerator = MUL_ZZ_Z(a.numerator, bden); // получаем числитель результирующей дроби
	c.denominator = MUL_ZZ_Z(aden, b.numenator);// получаем знаменатель результирующей дроби
	// получаем знак результирующей дроби:
	if (c.numerator->isPositive == c.denominator->isPositive)
		c.numerator->isPositive = 1;
	else
		c.numerator->isPositive = 0;
	return c;
}

#endif  // DIV_QQ_Q_CPP