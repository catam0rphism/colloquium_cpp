natural SUB_NDN_N(const natural n1, const unsigned short d, const natural n2)
{
	natural x,y,p;
	if (NZER_N_B(n1))
	{
		x.count=0;
		x=NEWN_N_N(x);
		return x;
	};
	if (NZER_N_B(n2) || !d)
	{
		x=DELZ_N_N(n1);
		return x;
	};
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	p=MUL_ND_N(y,d);
	DELN_N(y);
	y=p;
	if (COM_NN_D(x,y)==1)
	{
		p=SUB_NN_N(x,y);
		DELN_N(x);
		DELN_N(y);
		return p;
	}
	else
	{
		DELN_N(x);
		DELN_N(y);
		y.count=0;
		y=NEWN_N_N(y);
		return y;
	};
}; 
