natural MUL_NN_N(const natural n1, const natural n2)
{
	natural x,y,sum;
	if (NZER_N_B(n1) || NZER_N_B(n2))
	{
		x.count=0;
		x=NEW_N_N(x);
		return x;
	};
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	sum.count=0;
	sum=NEW_N_N(sum);
	for(register unsigned short i=0;i<x.count;i++)
	{
		natural p=MUL_ND_N(y,x.digits[i]);
		natural z=MUL_Nk_N(p,i);
		DEL_N(p);
		p=ADD_NN_N(sum,z);
		DEL_N(sum);
		DEL_N(z);
		sum=p;
	};
	DEL_N(x);
	DEL_N(y);
	return sum;
}
