// Copyright 2015   4371
#ifndef DIV_NN_Dk
#define DIV_NN_Dk

#include "../../structs/struct.h"

natural DIV_NN_Dk(const natural& a, const natural& b)
{
	natural res = a;
	unsigned n;
	n = a.order() - b.order();
	natural sub = MUL_Nk_N (b, n);
	digit k = _0;
	bool overflowFlag = false;
	while (COM_NN_D(res, sub) != ordinal::GT)
	{
		n--;
		sub = MUL_Nk_N (b, n);
	}
	while (COM_NN_D(res, sub) == ordinal::GT)
	{
		res = SUB_NN_N(res, sub);
		inc(res[k], overflowFlag);
	}
	return k;
}

#endif
