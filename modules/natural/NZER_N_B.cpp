bool NZER_N_B(const natural n)
{
	natural x=DELZ_N_N(n);
	unsigned short count=x.count;
	DEL_N(x);
	if (count) return 0;
	else return 1;
};
