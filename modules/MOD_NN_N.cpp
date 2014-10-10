natural MOD_NN_N(const natural n1, const natural n2)
{
	natural z;
	z.count=1;
	z=NEWN_N_N(z);
	z.digits[0]=1;
	if (NZER_N_B(n1) || !COM_NN_D(DELZ_N_N(n2),z))
	{
		natural x;
		x.count=0;
		x=NEWN_N_N(x);
		DELN_N(z);
		return x;
	}
	if (NZER_N_B(n2))
	{
		natural x=ADD_1N_N(n1);
		return x;
	};
	DELN_N(z);
	natural x=DELZ_N_N(n1),y=DELZ_N_N(n2);
	switch (COM_NN_D(x,y))
	{
		case 0:
			DELN_N(x);
			DELN_N(y);
			x.count=0;
			x=NEWN_N_N(x);
			return x;
		break;
		case 1:
			z=SUB_NN_N(x,MUL_NN_N(DIV_NN_N(x,y),y));
			DELN_N(x);
			DELN_N(y);
			return z;
		break;
		case 2:
			DELN_N(y);
			return x;
		break;
	};
};
