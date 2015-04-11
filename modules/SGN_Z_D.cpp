unsigned short SGN_Z_D(const integer z)
{
	integer x=DELZ_Z_Z(z);
	if (!x.module.count) return 0;
	else
		if (x.sign) return 2;
		else return 1; 
}
