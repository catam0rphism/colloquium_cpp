//Copyright 2015 Rusyaev Sergey, Vasil'eva Maria

#include "stdafx.h"
#include "struct.h"
#include <iostream>


int POZ_Z_D(const integer& a)
{
	int k;
	if (a.module == 0)
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
	return k;
}
