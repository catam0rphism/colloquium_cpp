integer DELZ_Z_Z(const integer z)
{
	integer x;
	x.module=DELZ_N_N(z.module);
	x.sign=z.sign;
	return x;
}
