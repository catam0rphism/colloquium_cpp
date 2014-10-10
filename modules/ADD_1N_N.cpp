natural ADD_1N_N(const natural n)
{
	natural x,y;
	x=DELZ_N_N(n);
	y.count=x.count;
	unsigned short i=0;
	for(;i<x.count && x.digits[i]==9;i++);
	if (i==x.count) 
	{
		y.count++;
		y=NEW_N_N(y);
		for(register unsigned short j=0;j<y.count-1;j++)
			y.digits[j]=0;
		y.digits[y.count-1]=1;
	}
	else
	{
		y=COPY_N_N(x);
		for(register unsigned short j=0;j<i;j++)
			y.digits[j]=0;
		y.digits[i]++;
	};
	return y;
};
