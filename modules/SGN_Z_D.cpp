unsigned short SGN_Z_D(const integer z)
{
	if (NZER_N_B(z.module)) return 0;
	else
		if (z.sign) return 2;
		else return 1; 
}
