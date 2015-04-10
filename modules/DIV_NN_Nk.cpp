natural DIV_NN_Nk(const natural n1, const natural n2)
{
	natural x,y,z;
	if (NZER_N_B(n1))
	{
		x.count=0;
		x=NEW_N_N(x);
		return x;
	};
	if (NZER_N_B(n2))
	{
		x=ADD_1N_N(n1);
		return x;
	};
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	switch (COM_NN_D(x,y))
	{
		case 0:
			DEL_N(x);
			DEL_N(y);
			x.count=1;
			x=NEW_N_N(x);
			x.digits[0]=1;
			return x;
		break;
		case 2:
			DEL_N(x);
			DEL_N(y);
			x.count=0;
			x=NEW_N_N(x);
			return x;
		break;
	};
	unsigned short k=0,d=0;
	z.count=0;
	z=NEW_N_N(z);
	do
	{
		k++;
		DEL_N(z);
		z=MUL_Nk_N(y,k);
	} while (COM_NN_D(x,z)<2);
	k--;
	DEL_N(z);
	z=MUL_Nk_N(y,k);
	DEL_N(y);
	while (COM_NN_D(x,z)<2)
	{
		y=SUB_NN_N(x,z);
		DEL_N(x);
		x=y;
		d++;
	};
	y.count=1;
	y=NEW_N_N(y);
	y.digits[0]=d;
	DEL_N(z);
	z=MUL_Nk_N(y,k);
	DEL_N(x);
	DEL_N(y);
	return z;
};
