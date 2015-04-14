natural GCF_NN_N(const natural n1,const natural n2)
{
	natural x=DELZ_N_N(n1),y=DELZ_N_N(n2);
	if (NZER_N_B(x) || !COM_NN_D(x,y))
	{
		DEL_N(x);
		return y;
	};
	if (NZER_N_B(y))
	{
		DEL_N(y);
		return x;
	};
	natural one;
	one.count=1;
	one=NEW_N_N(one);
	one.digits[0]=1;
	natural x1=ADD_1N_N(x),y1=ADD_1N_N(y);
	if (!COM_NN_D(x,one) || !COM_NN_D(y,one) || !COM_NN_D(x1,y) || !COM_NN_D(y1,x))
	{
		DEL_N(x);
		DEL_N(y);
		DEL_N(x1);
		DEL_N(y1);
		return one;
	};
	DEL_N(x1);
	DEL_N(y1);
	DEL_N(one);
	if (COM_NN_D(x,y)==2)
	{
		natural z=x;
		x=y;
		y=z;
	};
	for(register natural z=MOD_NN_N(x,y);!NZER_N_B(y);z=MOD_NN_N(x,y))
	{
		DEL_N(x);
		x=y;
		y=z;
	};
	DEL_N(y);
	return x;
};
