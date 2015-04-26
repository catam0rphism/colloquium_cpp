#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../structs/struct.h"
#include "../modules/natural/natural.h"

TEST_CASE ( "Натуральные числа", "[natural]" ) {
    
    #ifdef COM_NN_D_CPP
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
    #endif  // COM_NN_D_CPP

    #ifdef ADD_1N_N_CPP
    SECTION ( "ADD_1N_N [инкремент]" ) {
        natural a = { _9, _9, _8 };

        a = ADD_1N_N(a);
        REQUIRE ( COM_NN_D(a, {_9, _9, _9 }) == ordinal::EQ );

        a++;
        REQUIRE ( COM_NN_D(a, {_1, _0, _0, _0 }) == ordinal::EQ );
    }
    #endif  // ADD_1N_N_CPP
    
    #ifdef SUB_NN_N_CPP
    SECTION ( "SUB_NN_N [разность большего и меньшего чисел]" ) {
        natural a = { _1, _0, _0 };
        natural b = { _1 };
        
        REQUIRE ( COM_NN_D( SUB_NN_N(a, b), { _9, _9 }) == ordinal::EQ );
        
        a = a - a;
        REQUIRE ( COM_NN_D( a, { _0 }) == ordinal::EQ );

        a = { _5, _3, _9 };
        b = { _4, _2, _8};
        REQUIRE ( COM_NN_D( SUB_NN_N(a, b), { _1, _1, _1 }) == ordinal::EQ );
    }
    #endif  // SUB_NN_N_CPP

    #ifdef NZER_N_B_CPP
    SECTION ("NZER_N_B [проверка на ноль]") {
        natural zero = { _0 };
        natural nzero = { _1, _0, _4, _2 };

        REQUIRE ( NZER_N_B(zero) );
        REQUIRE_FALSE ( NZER_N_B(nzero) );

        zero = { _0, _0 };
        REQUIRE ( NZER_N_B(zero) );

        nzero = { _0, _0, _1, _0, _0 };
        REQUIRE_FALSE ( NZER_N_B(nzero) );
    }
    #endif  // NZER_N_B_CPP

    #ifdef  MUL_ND_N_CPP
    SECTION("MUL_ND_N [умножение натурального числа на цифру]") {
        natural zero = { _0 };
        natural one = { _1 };
        natural totallyRandomNumber("424242424242");
        natural result9("3818181818178");

        REQUIRE(COM_NN_D(MUL_ND_N(zero, _1), zero) == ordinal::EQ);
        REQUIRE(COM_NN_D(MUL_ND_N(one, _9), { _9 }) == ordinal::EQ);
        REQUIRE(COM_NN_D(MUL_ND_N(totallyRandomNumber, _9), result9) == ordinal::EQ);
    }
    #endif  // MUL_ND_N_CPP

    #ifdef MUL_NN_N_CPP
    SECTION("MUL_NN_N [умножение натурального числа на натуральное]") {
        natural totallyRandomNumber("424242424242");
        natural resultSquare("179981634526729109274564");

        REQUIRE(COM_NN_D(MUL_NN_N(totallyRandomNumber, totallyRandomNumber),
            resultSquare) == ordinal::EQ);
    }
    #endif  // MUL_NN_N_CPP

    #ifdef MUL_NK_N_CPP
    SECTION("MUL_Nk_N [умножение натурального числа на 10^k]") {
        natural totallyRandomNumber("42");
        natural result4("420000");
        REQUIRE(COM_NN_D(MUL_Nk_N(totallyRandomNumber, 4), result4) == ordinal::EQ);
        REQUIRE(COM_NN_D(MUL_Nk_N(totallyRandomNumber, 0), totallyRandomNumber) == ordinal::EQ);
    }
    #endif  // MUL_NK_N_CPP
}
