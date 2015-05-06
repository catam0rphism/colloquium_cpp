//27.04.2015: Rombalskaya Alena, Zaplatkina Ksenya 4373


fraction MUL_QQ_Q(fraction Num1, fraction Num2)  //   умножение дробей
{
	fraction Num3;
	Num3.numerator = MUL_ZZ_Z(Num1.numerator, Num2.numerator);       // перемножение числителей первой и второй дробей
	Num3.denominator = MUL_NN_N(Num1.denominator, Num2.denominator); // перемножение знаменателей первой и второй дробей  
	Num3 = RED_Q_Q(Num3);     // упрощение полученной дроби
	return (Num3);
}

