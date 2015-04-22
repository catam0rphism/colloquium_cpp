#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../structs/struct.h"
#include "../modules/natural/natural.h"

TEST_CASE ( "Натуральные числа", "[natural]" ) {
    SECTION ( "COM_NN_D [сравнение]" ) {
        natural a, b;

        a = { _4, _2 };

        // рефлексивность
        REQUIRE ( a == a );

        a = { _9, _8 };
        b = { _8, _9 };

        // Симметричность
        REQUIRE ( COM_NN_D(a, b) == ordinal::GT );
        REQUIRE ( COM_NN_D(b, a) == ordinal::LT );

        natural c = { _7 };

        // транзитивность
        REQUIRE ( COM_NN_D(b, c) == ordinal::GT );
        REQUIRE ( COM_NN_D(a, c) == ordinal::GT );

        a = { _0, _1, _2 };
        b = { _1, _0, _0 };

        REQUIRE ( COM_NN_D(a, b) == ordinal::LT );
    }

    SECTION ( "ADD_1N_N [инкремент]" ) {
        natural a = { _9, _9, _8 };

        a = ADD_1N_N(a);
        REQUIRE ( COM_NN_D(a, {_9, _9, _9 }) == ordinal::EQ );

        a++;
        REQUIRE ( COM_NN_D(a, {_1, _0, _0, _0 }) == ordinal::EQ );
    }
    
    SECTION ( "SUB_NN_N [разность большего и меньшего чисел]" ) {
        natural a = { _1, _0, _0 };
        natural b = { _1 };
        
        REQUIRE ( COM_NN_D( SUB_NN_N(a, b), { _9, _9 }) == ordinal::EQ );
        
        a = a - a;
        REQUIRE ( COM_NN_D( SUB_NN_N(a, b), { _0 }) == ordinal::EQ );
    }
}
