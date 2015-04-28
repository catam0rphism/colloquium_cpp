// Copyright 2015   4371
#ifndef DIV_NN_Dk_CPP
#define DIV_NN_Dk_CPP

#include "../../structs/struct.h"

#include "MUL_Nk_N.cpp"
#include "COM_NN_D.cpp"
#include "SUB_NN_N.cpp"

natural DIV_NN_Dk(const natural& a, const natural& b)
{
    natural res = a;
    unsigned n;
    n = a.order() - b.order();
    natural sub = MUL_Nk_N(b, n);
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

#endif  // DIV_NN_Dk_CPP
