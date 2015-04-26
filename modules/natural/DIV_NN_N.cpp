#ifndef DIV_NN_N
#define DIV_NN_N

#include "../../structs/struct.h"

natural DIV_NN_N(const natural& a, const natural& b)
{
	natural res;
	natural divident = a;
	natural divider = b;
	digit fact = _0;
	while (COM_NN_D(divident, divider) == ordinal::GT)
	{
		fact = DIV_NN_Dk(divident, divider);
		divident = SUB_NDN_N(divident, divider, fact);
		res.insert(res.begin(), fact);
	}
	return res;
}

#endif