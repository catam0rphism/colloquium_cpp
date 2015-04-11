integer MUL_Z_Z(const integer z)
{
	integer x=DELZ_Z_Z(z);
	if (x.module.count) x.sign=!x.sign;
	else x.sign=0;
	return x;
}
