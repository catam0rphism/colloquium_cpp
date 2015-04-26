// Copyright 2015 Галеева, Межуева 4371
#ifndef SUB_NDN_N
#define SUB_NDN_N

#include "../../structs/struct.h"

natural SUB_NDN_N(const natural& a, const natural& b, const digit& n)
{
	natural res = a;
	natural mul_sub = b;
	digit fact = n;
	mul_sub = MUL_ND_N (mul_sub, fact);
	if (COM_NN_D(res, mul_sub) == ordinal::GT)
	{
		res = SUB_NN_N(res, mul_sub);
		return res;
	}
	//else что возвращать в случае, когда произведение больше?
}

#endif