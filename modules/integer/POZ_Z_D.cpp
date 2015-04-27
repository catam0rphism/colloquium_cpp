//Copyright 2015 Rusyaev Sergey, Vasil'eva Maria

int POZ_Z_D(const integer& a) // ПОчему не bool!?
{
	int k;
	if (a.module == 0) // Не будет работать!
	{
		k = 0;
	}
	else
	{
		if (a.isPositive == true)
			k = 1;
		else
			k = 0;
	}
	return k; // Почему вообще есть весь код выше, а не просто return a.isPositive!?
}
