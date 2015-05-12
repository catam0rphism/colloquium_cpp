// Copyright 2015 Dedov Andrey
#ifndef NZER_N_B_CPP
#define NZER_N_B_CPP

#include "../../structs/struct.h"

bool NZER_N_B (natural a)
{
    return (a.order() == 1 && a[0] == _0);
}

#endif // NZER_N_B_CPP
