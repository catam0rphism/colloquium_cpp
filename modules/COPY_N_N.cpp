natural COPY_N_N(const natural n1)
{
	natural x;
	x.count=n1.count;
	x=NEW_N_N(x);
	for(register unsigned short i=0;i<n1.count;i++)
		x.digits[i]=n1.digits[i];
	return x;
}
