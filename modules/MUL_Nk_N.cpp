natural MUL_Nk_N(const natural n, const unsigned short k)
{
	natural x,y;
	if (NZER_N_B(n))
	{
		x.count=0;
		x=NEWN_N_N(x);
		return x;
	};
	x=DELZ_N_N(n);
	y.count=x.count+k;
	y=NEWN_N_N(y);
	for(register unsigned short i=0;i<k;i++)
		y.digits[i]=0;
	for(register unsigned short i=k;i<y.count;i++)
		y.digits[i]=x.digits[i-k];
	DELN_N(x);
	return y;
};
