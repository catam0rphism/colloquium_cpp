natural SUB_NN_N(const natural n1, const natural n2)
{
	natural x,y;
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	switch (COM_NN_D(x,y))
	{
		case 0:
			DELN_N(x);
			DELN_N(y);
			x.count=0;
			x=NEWN_N_N(x);
			return x;
		case 2:
			natural z=x;
			x=y;
			y=z;
		break;
	}
	for(register unsigned short i=0;i<y.count;i++)
		if (x.digits[i]<y.digits[i])
		{
			x.digits[i]+=10-y.digits[i];
			x.digits[i+1]--;
		}
		else x.digits[i]-=y.digits[i];
	DELN_N(y);
	y=DELZ_N_N(x);
	DELN_N(x);
	return y;
};
