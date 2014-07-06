natural ADD_NN_N(const natural n1, const natural n2)
{
	natural x,y;
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	if (COM_NN_D(x,y)==2)
	{
		natural z=x;
		x=y;
		y=z;
	};
	for(register unsigned short i=0;i<y.count;i++)
	{
		x.digits[i]+=y.digits[i];
		register unsigned short j=i;
		while (x.digits[j]>9 && j+1<x.count)
		{
			x.digits[j]%=10;
			x.digits[j+1]++;
			j++;
		};
	};
	if (x.digits[x.count-1]>9)
	{
		DELN_N(y);
		y.count=x.count+1;
		NEWN_N_N(y);
		for(register unsigned short i=0;i<x.count-1;i++)
			y.digits[i]=x.digits[i];
		y.digits[x.count-1]=x.digits[x.count-1]%10;
		y.digits[x.count]=1;
		DELN_N(x);
		return y;
	}
	else
	{
		DELN_N(y);
		return x;
	};
};
