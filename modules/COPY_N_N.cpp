natural COPY_N_N(const natural n1)
{
	natural x=DELZ_N_N(n1);
	for(register unsigned short i=0;i<x.count;i++)
		x.digits[i]=n1.digits[i];
	return x;
}
