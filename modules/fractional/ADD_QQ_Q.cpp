//4373 28.04.15 Omeluk, Mokeev

fraction ADD_QQ_Q(fraction a, fraction b)
{
	fraction sum = 0;
	if (b.denominator == a.denominator)//сравнение знаменателей слагаемых
	{	
		sum.denominator = b.denominator;//если равны, присвоить сумме знаменатель слагаемых
		sum.numerator = ADD_ZZ_Z(a.numerator,b.numerator);//
		return sum;
	}
	else{
		sum.denominator = LCM_NN_N(a, b);
		sum.numerator = ADD_ZZ_Z((MUL_ZZ_Z(a.numerator, TRANS_N_Z(sum.denominator / a.denominator))), MUL_ZZ_Z(b.numerator, TRANS_N_Z(sum.denominator / b.denominator)));
		return sum;
	}
}
