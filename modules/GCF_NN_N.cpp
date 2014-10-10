natural GCF_NN_N(const natural n1,const natural n2)
{
	natural x=DELZ_N_N(n1),y=DELZ_N_N(n2);
	if (NZER_N_B(x) || !COM_NN_D(x,y))
	{
		DEL_N(x);
		return y;
	}
	else
		if (NZER_N_B(y))
		{
			DEL_N(y);
			return x;
		};
	
	while(!NZER_N_B(x) && !NZER_N_B(y))
	{
		natural z;
		switch(COM_NN_D(x,y))
		{
			case 1:
				
			break;
	};
};
