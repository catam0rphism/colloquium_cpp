unsigned short COM_NN_D(const natural n1, const natural n2)
{
	natural x,y;
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	if (x.count>y.count) 
	{
		DEL_N(x);
		DEL_N(y);
		return 1;
	};
	if (x.count<y.count) 
	{
		DEL_N(x);
		DEL_N(y);
		return 2;
	};
	for(register unsigned short i=x.count-1;i>=0 && i<x.count;i--)
	{
		if (x.digits[i]>y.digits[i])
		{
			DEL_N(x);
			DEL_N(y);
			return 1;
		};
		if (x.digits[i]<y.digits[i])
		{
			DEL_N(x);
			DEL_N(y);
			return 2;
		};
	};
	DEL_N(x);
	DEL_N(y);
	return 0;
};
