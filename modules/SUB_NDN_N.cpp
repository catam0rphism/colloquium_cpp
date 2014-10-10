natural SUB_NDN_N(const natural n1, const unsigned short d, const natural n2)
{
	natural x,y,p;
	if (NZER_N_B(n1))
	{
		x.count=0;
		x=NEW_N_N(x);
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
	DEL_N(y);
	y=p;
	if (COM_NN_D(x,y)==1)
	{
		p=SUB_NN_N(x,y);
		DEL_N(x);
		DEL_N(y);
		return p;
	}
	else
	{
		DEL_N(x);
		DEL_N(y);
		y.count=0;
		y=NEW_N_N(y);
		return y;
	};
}; 
