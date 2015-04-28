#ifndef DIV_NN_N_CPP
#define DIV_NN_N_CPP

#include "../../structs/struct.h"

#include "COM_NN_D.cpp"
#include "DIV_NN_Dk.cpp"
#include "SUB_NDN_N.cpp"

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
        #warning Нет инсерта =(
        res.insert(res.begin(), fact);
    }
    return res;
}

#endif  // DIV_NN_N_CPP