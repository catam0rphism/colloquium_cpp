natural MOD_NN_N(const natural n1, const natural n2)
{
	natural one,z=DELZ_N_N(n2);
	one.count=1;
	one=NEW_N_N(one);
	one.digits[0]=1;
	if (NZER_N_B(n1) || !COM_NN_D(z,one))
	{
		natural x;
		x.count=0;
		x=NEW_N_N(x);
		DEL_N(one);
		DEL_N(z);
		return x;
	}
	if (NZER_N_B(n2))
	{
		natural x=ADD_1N_N(n1);
		DEL_N(one);
		DEL_N(z);
		return x;
	};
	DEL_N(z);
	DEL_N(one);
	natural x=DELZ_N_N(n1),y=DELZ_N_N(n2);
	switch (COM_NN_D(x,y))
	{
		case 0:
			DEL_N(x);
			DEL_N(y);
			x.count=0;
			x=NEW_N_N(x);
			return x;
		break;
		case 1:
			z=DIV_NN_N(x,y);
			one=MUL_NN_N(z,y);
			DEL_N(z);
			z=SUB_NN_N(x,one);
			DEL_N(one);
			DEL_N(x);
			DEL_N(y);
			return z;
		break;
		case 2:
			DEL_N(y);
			return x;
		break;
	};
};
