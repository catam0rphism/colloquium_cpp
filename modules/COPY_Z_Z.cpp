integer COPY_Z_Z(const integer z)
{
	integer x;
	x.module=COPY_N_N(z.module);
	x.sign=z.sign;
	return x;
}
