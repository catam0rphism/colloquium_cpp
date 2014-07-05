natural ADD_1N_N(const natural n)
{
	natural x,y;
	x=DELZ_N_N(n);
	y.count=x.count;
	unsigned short i=0;
	for(;i<x.count && x.digits[i]==9;i++);
	if (i==x.count) y.count++;
	y=NEWN_N_N(y);
	if (i==x.count) y.digits[i]=1;
	else (y.digits[i]=x.digits[i]+1);
	for(register unsigned short j=0;j<i;j++)
		y.digits[j]=0;
	for(register unsigned short j=i+1;j<x.count;j++)
		y.digits[j]=x.digits[j];
	DELN_N(x);
	return y;
};
