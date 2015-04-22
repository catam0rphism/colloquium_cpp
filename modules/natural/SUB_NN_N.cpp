// Copyright 2015 Golovnia Ian
#ifndef SUB_NN_N_CPP
#define SUB_NN_N_CPP

// #include <algorithm>

#include "../../structs/struct.h"
#include "COM_NN_D.cpp"

natural SUB_NN_N(const natural& a, const natural& b) {
    natural ltNum, gtNum;

    if (COM_NN_D(a, b) == ordinal::LT) {
        ltNum = a;
        gtNum = b;
    } else {
        ltNum = b;
        gtNum = a;
    }

    natural res = gtNum;

    bool insufficienceFlag = false;
    for (int i = 0; i <= ltNum.order(); i++)  {
        res[i] = sub(res[i], ltNum[i], insufficienceFlag);
    }

    int k = ltNum.order();
    while (insufficienceFlag) {
        insufficienceFlag = false;
        res[k + 1] = sub(res[k + 1], _1, insufficienceFlag);
        k++;
    }

    return res;

}

natural natural::operator-(const natural& other) {
    return SUB_NN_N(*this, other);
}

#endif  // SUB_NN_N_CPP