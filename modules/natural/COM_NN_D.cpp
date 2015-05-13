// Copyright 2015 Bratkovsky Dmitry
#ifndef COM_NN_D_CPP
#define COM_NN_D_CPP

#include "../../structs/struct.h"

#define DEBUG_MODE

ordinal COM_NN_D(const natural& l, const natural& r) {
    // natural a(left);
    // natural b(right);
    // int r = 0;  // TODO(Belkin Dmitriy): r не нужно

    // if (a.order() == b.order()) {
    //     for (int i = a.order(); (i >= 0) && (r != 1) && (r != 2); --i) {
    //         if (a[i] > b[i]) {
    //             r = 1;
    //             break;
    //         }
    //         if (a[i] < b[i]) {
    //             r = 2;
    //             break;
    //         }
    //     }
    // } else {
    //     if (a.order() > b.order())
    //         r = 1;
    //     else
    //         r = 2;
    // }
    // switch (r) {
    // case 0:
    //     return ordinal::EQ;
    //     break;
    // case 1:
    //     return ordinal::GT;
    //     break;
    // case 2:
    //     return ordinal::LT;
    //     break;
    // default: throw;
    // }
    if (l.order() > r.order()) { return ordinal::GT; }
    else if (l.order() < r.order()) { return ordinal::LT; }
    else if (l.order() == r.order()) {        
        for (int i = l.order(); i >= 0; i--) {
            if (l[i] != r[i]) {            
                return ord(l[i], r[i]);
            }
        }
    }
    return ordinal::EQ;
}

bool operator==(const natural &left, const natural& right) {
    return ordinal::EQ == COM_NN_D(left, right);
}

bool operator<(const natural &left, const natural& right) {
    return ordinal::LT == COM_NN_D(left, right);
}

bool operator>(const natural &left, const natural& right) {
    return ordinal::GT == COM_NN_D(left, right);
}

bool operator>=(const natural &left, const natural& right) {
    return !(left < right);
}

bool operator<=(const natural &left, const natural& right) {
    return !(left > right);
}

#endif  // COM_NN_D_CPP
