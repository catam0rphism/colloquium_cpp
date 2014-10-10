natural MUL_ND_N(const natural n, const unsigned short d)
{
	natural x,y;
	if (NZER_N_B(n) || !d)
	{
		x.count=0;
		x=NEW_N_N(x);
		return x;
	};
	x=DELZ_N_N(n);
	if (d==1) return x;
	y.count=0;
	y=NEW_N_N(y);
	for(register unsigned short i=0;i<x.count;i++)
	{
		unsigned short z=x.digits[i]*d;
		natural p,l;
		if (z>9) p.count=2;
		else p.count=1;
		p=NEW_N_N(p);
		p.digits[0]=z%10;
		if (z>9) p.digits[1]=z/10;
		l=MUL_Nk_N(p,i);
		DEL_N(p);
		p=ADD_NN_N(y,l);
		DEL_N(y);
		y=p;
	};
	return y;
}; 
