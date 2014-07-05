bool NZER_N_B(const natural n)
{
	natural x;
	x=DELZ_N_N(n);
	if (x.count) return 0;
	else return 1;
};
