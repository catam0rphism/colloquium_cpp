// Copyright 2015 Dmitriy Belkin
// Copyright 2015 Vadim Bertysh
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../structs/struct.h"
#include "../modules/natural/natural.h"
#include "../modules/integer/integer.h"

TEST_CASE("Натуральные числа", "[natural]") {

#ifdef COM_NN_D_CPP
	SECTION("COM_NN_D [сравнение]") {
		natural a, b;

		a = { _4, _2 };

		// рефлексивность
		REQUIRE(a == a);

		a = { _9, _8 };
		b = { _8, _9 };

		// Симметричность
		REQUIRE(COM_NN_D(a, b) == ordinal::GT);
		REQUIRE(COM_NN_D(b, a) == ordinal::LT);

		natural c = { _7 };

		// транзитивность
		REQUIRE(COM_NN_D(b, c) == ordinal::GT);
		REQUIRE(COM_NN_D(a, c) == ordinal::GT);

		a = { _0, _1, _2 };
		b = { _1, _0, _0 };

		REQUIRE(COM_NN_D(a, b) == ordinal::LT);
	}
#endif  // COM_NN_D_CPP

#ifdef ADD_1N_N_CPP
	SECTION("ADD_1N_N [инкремент]") {
		natural a = { _9, _9, _8 };

		a = ADD_1N_N(a);
		REQUIRE(COM_NN_D(a, { _9, _9, _9 }) == ordinal::EQ);

		a++;
		REQUIRE(COM_NN_D(a, { _1, _0, _0, _0 }) == ordinal::EQ);
	}
#endif  // ADD_1N_N_CPP

#ifdef SUB_NN_N_CPP
	SECTION("SUB_NN_N [разность большего и меньшего чисел]") {
		natural a = { _1, _0, _0 };
		natural b = { _1 };

		REQUIRE(COM_NN_D(SUB_NN_N(a, b), { _9, _9 }) == ordinal::EQ);

		a = a - a;
		REQUIRE(COM_NN_D(a, { _0 }) == ordinal::EQ);

		a = { _5, _3, _9 };
		b = { _4, _2, _8 };
		REQUIRE(COM_NN_D(SUB_NN_N(a, b), { _1, _1, _1 }) == ordinal::EQ);
	}
#endif  // SUB_NN_N_CPP

#ifdef NZER_N_B_CPP
	SECTION("NZER_N_B [проверка на ноль]") {
		natural zero = { _0 };
		natural nzero = { _1, _0, _4, _2 };

		REQUIRE(NZER_N_B(zero));
		REQUIRE_FALSE(NZER_N_B(nzero));

		zero = { _0, _0 };
		REQUIRE(NZER_N_B(zero));

		nzero = { _0, _0, _1, _0, _0 };
		REQUIRE_FALSE(NZER_N_B(nzero));
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

#ifdef DIV_NN_Dk_CPP
	SECTION("DIV_NN_Dk [Первая цифра деления и правильная степень 10]") {
		natural a("815");
		natural b("27");

		auto p = DIV_NN_Dk(a, b);
		REQUIRE(p.first == _3);
		REQUIRE(p.second == 1);

		a = natural("123");
		b = natural("7");

		p = DIV_NN_Dk(a, b);
		REQUIRE(p.first == _1);
		REQUIRE(p.second == 1);

		a = natural("999");
		b = natural("111");

		p = DIV_NN_Dk(a, b);
		REQUIRE(p.first == _9);
		REQUIRE(p.second == 0);

		a = natural("6000");
		b = natural("2");

		p = DIV_NN_Dk(a, b);
		REQUIRE(p.first == _3);
		REQUIRE(p.second == 3);
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
		REQUIRE(LCM_NN_N(a, c) == d);

		natural zero;
		REQUIRE(LCM_NN_N(c, zero) == zero);
	}
#endif
}

TEST_CASE( "Целые числа", "[integer]" ) {

#ifdef ABS_Z_N_CPP
    SECTION( "ABS_Z_N [модуль]" ) {
        integer a("-423");
        natural b("423");
        REQUIRE(ABS_Z_N(a) == b);

        integer antizero("-0");
        natural zero;
        REQUIRE(ABS_Z_N(antizero) == zero);

        integer c("423");
        REQUIRE(ABS_Z_N(a) == ABS_Z_N(c));
    }
#endif

#ifdef ADD_ZZ_Z_CPP
    SECTION( "ADD_ZZ_Z [сложение]" ) {
        integer a(23);
        integer b(-3);
        // Работоспособность
        REQUIRE(ADD_ZZ_Z(a, b) == integer(20));

        integer nega(-23);
        // Нолик
        REQUIRE(ADD_ZZ_Z(a, nega) == integer(0));

        // Коммутативность
        REQUIRE(ADD_ZZ_Z(a, b) == ADD_ZZ_Z(b, a));

		integer c(42);
        // Ассоциативность
        REQUIRE(ADD_ZZ_Z(ADD_ZZ_Z(a, b), c) == ADD_ZZ_Z(a, ADD_ZZ_Z(b, c)));
    }
#endif

#ifdef COM_ZZ_D_CPP
    SECTION("COM_ZZ_D [сравнение]") {
        integer zero;
        integer antizero("-0");
        REQUIRE(COM_ZZ_D(zero, antizero) == ordinal::EQ);

        integer a(42);
        integer b(-42);
        REQUIRE(COM_ZZ_D(a, b) == ordinal::GT);
        REQUIRE(COM_ZZ_D(b, a) == ordinal::LT);
        REQUIRE(COM_ZZ_D(a, a) == ordinal::EQ);
        REQUIRE(COM_ZZ_D(b, b) == ordinal::EQ);
    }
#endif // COM_ZZ_D_CPP


#ifdef DIV_ZZ_Z_CPP
    SECTION( "DIV_ZZ_Z [деление]" ) {
        integer a(-16);
        integer b(4);
        integer c(-4);
        REQUIRE(DIV_ZZ_Z(a, b) == c);
		REQUIRE(DIV_ZZ_Z(a, c) == b);

        integer negone(-1);
        REQUIRE(DIV_ZZ_Z(b, c) == negone);

        integer zero;
        REQUIRE_THROWS(DIV_ZZ_Z(a, zero));
    }
#endif

#ifdef INV_Z_Z_CPP
    SECTION( "INV_Z_Z [умножение на -1]" ) {
        integer a(4);
        integer b(-4);
        REQUIRE(INV_Z_Z(a) == b);
        REQUIRE(INV_Z_Z(b) == a);
        REQUIRE(INV_Z_Z(INV_Z_Z(a)) == a);

        integer zero;
        REQUIRE(INV_Z_Z(zero) == zero);
    }
#endif

#ifdef MOD_ZZ_Z_CPP
    SECTION( "MOD_ZZ_Z [остаток от деления]" ) {
        integer a(16);
        integer nega(-16);
        integer b(3);
        integer negb(-3);
        REQUIRE(MOD_ZZ_Z(a, nega) == integer(0));
        REQUIRE(MOD_ZZ_Z(a, b) == integer(1));
        REQUIRE(MOD_ZZ_Z(a, negb) == integer(1));
        REQUIRE(MOD_ZZ_Z(nega, b) == integer(2));
        REQUIRE(MOD_ZZ_Z(b, a) == b);
        integer zero;
        REQUIRE_THROWS(MOD_ZZ_Z(a, zero));
    }
#endif

#ifdef MUL_ZZ_Z_CPP
    SECTION( "MUL_ZZ_Z [умножение]" ) {
        integer a(7);
        integer b(-6);
        integer nega(-7);
        REQUIRE(MUL_ZZ_Z(a, b) == integer(-42));
        REQUIRE(MUL_ZZ_Z(a, b) == MUL_ZZ_Z(b, a));
        REQUIRE(MUL_ZZ_Z(nega, b) == integer(42));
        REQUIRE(MUL_ZZ_Z(nega, b) == MUL_ZZ_Z(b, nega));
        integer zero;
        REQUIRE(MUL_ZZ_Z(nega, zero) == zero);
    }
#endif

#ifdef POZ_Z_D_CPP
    SECTION( "POZ_Z_D [положительность]" ) {
        integer a(42);
        integer b(-42);
        integer zero;
        REQUIRE(POZ_Z_D(a) == IntegerState::Positive);
        REQUIRE(POZ_Z_D(b) == IntegerState::Negative);
        REQUIRE(POZ_Z_D(zero) == IntegerState::Zero);
    }
#endif

#ifdef SUB_ZZ_Z_CPP
    SECTION( "SUB_ZZ_Z [вычитание]" ) {
        integer a(42);
        integer b(21);
        integer c(-21);
        integer zero;
        REQUIRE(SUB_ZZ_Z(a, a) == zero);
        REQUIRE(SUB_ZZ_Z(b, c) == a);
    }
#endif
}
