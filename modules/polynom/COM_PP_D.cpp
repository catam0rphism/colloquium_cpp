// Copyright 2015 Vadim Bertysh
// Во славу Императора котов, конечно
#ifndef COM_PP_D_CPP
#define COM_PP_D_CPP

#include "../../structs/struct.h"
#include "../../structs/ordinal.h"
#include "../fractional/COM_QQ_D.cpp"

ordinal COM_QQ_D(const polynom& left, const polynom& right) {
	if (left.degree() < right.degree())
		return ordinal::LT;
	if (left.degree() > right.degree())
		return ordinal::GT;
	for (int i = left.degree(); i >= 0; i--) {
		auto currComp = COM_QQ_D(left[i], right[i]);
		if (currComp != ordinal::EQ)
			return currComp;
	}
	return ordinal::EQ;
}

bool operator == (const polynom& left, const polynom& right) {
	return (COM_QQ_D(left, right) == ordinal::EQ);
}

#endif  // COM_PP_D_CPP
