natural DELZ_N_N(const natural n)
{
	natural x;
	x.count=n.count;
	x=NEW_N_N(x);
	for(register unsigned short i=n.count-1; i>=0 && i<n.count && !n.digits[i]; i--, x.count--);
	for(register unsigned short i=0;i<x.count;i++)
		x.digits[i]=n.digits[i];
	return x;
};
