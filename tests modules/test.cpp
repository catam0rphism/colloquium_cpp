bool test(const natural n1, const natural n2)
{
	if (n1.count!=n2.count) return 0;
	else
		for (register unsigned short i=0;i<n1.count;i++)
			if (n1.digits[i]!=n2.digits[i]) return 0;
	return 1;
};
/*bool test(const natural n)
{
	if (*(x.digits)) return 1;
	else return 0;
};*/
bool test(const unsigned short d1, const unsigned short d2)
{
	if (d1!=d2) return 0;
	else return 1;
};
bool test(const bool f1, const bool f2)
{
	if (f1!=f2) return 0;
	else return 1;
};
