integer TRANS_N_Z(const natural n)
{
	integer z;
	z.sign=0;
	z.module=DELZ_N_N(n);
	return z;
}
