// Copyright 2015 Vadim Bertysh
#ifndef LED_P_Q_CPP
#define LED_P_Q_CPP

#include "../../structs/struct.h"

fraction LED_P_Q(const polynom& input) {
    polynom temp = input;
    return temp[temp.degree()];
}

#endif  // LED_P_Q_CPP
