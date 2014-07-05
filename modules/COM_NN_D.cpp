unsigned short COM_NN_D(const natural n1, const natural n2)
{
	natural x,y;
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	if (x.count>y.count) 
	{
		DELN_N(x);
		DELN_N(y);
		return 1;
	};
	if (x.count<y.count) 
	{
		DELN_N(x);
		DELN_N(y);
		return 2;
	};
	for(register unsigned short i=x.count-1;i>=0 && i<x.count;i--)
	{
		if (x.digits[i]>y.digits[i])
		{
			DELN_N(x);
			DELN_N(y);
			return 1;
		};
		if (x.digits[i]<y.digits[i])
		{
			DELN_N(x);
			DELN_N(y);
			return 2;
		};
	};
	DELN_N(x);
	DELN_N(y);
	return 0;
};
