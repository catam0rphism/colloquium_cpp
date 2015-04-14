natural LCM_NN_N(const natural n1, const natural n2)
{
	natural x=DELZ_N_N(n1), y=DELZ_N_N(n2);
	if (NZER_N_B(x))
	{
		DEL_N(y);
		return x;
	};
	if (NZER_N_B(y) || !COM_NN_D(x,y))
	{
		DEL_N(x);
		return y;
	};
	natural z=GCF_NN_N(x,y);
	natural w=DIV_NN_N(x,z);
	DEL_N(x);
	x=MUL_NN_N(w,y);
	DEL_N(y);
	DEL_N(w);
	return x;
}
