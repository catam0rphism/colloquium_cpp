natural ADD_NN_N(const natural n1, const natural n2)
{
	natural x,y;
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	if (COM_NN_D(x,y)==2)
	{
		natural z;
		z=x;
		x=y;
		y=z;
	};
	for(register unsigned short i=0;i<y.count;i++)
	{
		x.digits[i]+=y.digits[i];
		if (x.digits[i]>9 && i+1<x.count)
		{
			x.digits[i]%=10;
			x.digits[i+1]++;
		};
	};
	DELN_N(y);
	y.count=x.count;
	if (x.digits[x.count-1]>9) y.count++;
	y=NEWN_N_N(y);
	if (x.digits[x.count-1]>9)
	{
		y.digits[x.count]=x.digits[x.count-1]/10;
		x.digits[x.count-1]%=10;
	};
	for(register unsigned short i=0;i<x.count;i++)
		y.digits[i]=x.digits[i];
	DELN_N(x);
	return y;
};
