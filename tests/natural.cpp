// Copyright 2015 Dmitriy Belkin
#ifndef NATURAL_CPP
#define NATURAL_CPP

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

        REQUIRE (COM_NN_D(MUL_ND_N(zero, _1), zero) == ordinal::EQ);
        REQUIRE (COM_NN_D(MUL_ND_N(one, _9), { _9 }) == ordinal::EQ);
        REQUIRE (COM_NN_D(MUL_ND_N(totallyRandomNumber, _9), result9) == ordinal::EQ);
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

    #ifdef DIV_NN_Dk_CPP
    SECTION("DIV_NN_Dk [Первая цифра деления и правильная степень 10]") {
        natural a("815");
        natural b("27");

        auto p = DIV_NN_Dk(a, b);
        REQUIRE( p.first == _3);
        REQUIRE( p.second == 1);

        a = natural("123");
        b = natural("7");

        p = DIV_NN_Dk(a, b);
        REQUIRE( p.first == _1);
        REQUIRE( p.second == 1);

        a = natural("999");
        b = natural("111");

        p = DIV_NN_Dk(a, b);
        REQUIRE( p.first == _9);
        REQUIRE( p.second == 0);

        a = natural("6000");
        b = natural("2");

        p = DIV_NN_Dk(a,b);
        REQUIRE( p.first == _3);
        REQUIRE( p.second == 3);
    }
    #endif

    #ifdef DIV_NN_N_CPP
    SECTION("DIV_NN_N [Деление натуральных чисел]") {
        natural a = { _1, _2, _3 };
        natural b = { _1, _0, _0 };
        natural c = { _2 };

        REQUIRE(DIV_NN_N(a, b) == natural({ _1 }));
        REQUIRE_FALSE(DIV_NN_N(a, c) == natural("24"));

		natural zero;
		REQUIRE_THROWS(DIV_NN_N(a, zero));
    }
    #endif

	#ifdef MOD_NN_N_CPP
	SECTION("MOD_NN_N [остаток от деления натуральных]") {
		natural a = { _1, _2, _3 };
		natural b = { _1, _0, _0 };
		natural c = { _2, _3 };
		REQUIRE(MOD_NN_N(a, b) == c);
	}
	#endif

	#ifdef GCF_NN_N_CPP
	SECTION("GCF_NN_N [НОД натуральных]") {
		natural a("42");
		natural b("21");
		REQUIRE(GCF_NN_N(a, b) == b);

		natural zero;
		REQUIRE(GCF_NN_N(a, zero) == a);
	}
	#endif

	#ifdef LCM_NN_N_CPP
	SECTION("LCM_NN_N [НОК натуральных]") {
		natural a("8");
		natural b("9");
		REQUIRE(LCM_NN_N(a, b) == MUL_NN_N(a, b));

		natural c("42");
		natural d("168");
		// REQUIRE(LCM_NN_N(a, c) == d);

		natural zero;
		REQUIRE(LCM_NN_N(c, zero) == zero);
	}
	#endif
}

#endif // NATURAL_CPP
