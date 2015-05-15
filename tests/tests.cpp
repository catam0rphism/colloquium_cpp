// Copyright 2015 Dmitriy Belkin
// Copyright 2015 Vadim Bertysh
// Copyright 2015 Inna Lizunova, 4373
// Copyright 2015 Karpova Liza, 4373
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../structs/struct.h"
#include "../modules/natural/natural.h"
#include "../modules/integer/integer.h"
#include "../modules/fractional/fractional.h"
#include "../modules/polynom/polynom.h"

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

TEST_CASE("Целые числа", "[integer]") {
#ifdef ABS_Z_N_CPP
    SECTION("ABS_Z_N [модуль]") {
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
    SECTION("ADD_ZZ_Z [сложение]") {
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
#endif  // COM_ZZ_D_CPP


#ifdef DIV_ZZ_Z_CPP
    SECTION("DIV_ZZ_Z [деление]") {
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
    SECTION("INV_Z_Z [умножение на -1]") {
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
    SECTION("MOD_ZZ_Z [остаток от деления]") {
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
    SECTION("MUL_ZZ_Z [умножение]") {
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
    SECTION("POZ_Z_D [положительность]") {
        integer a(42);
        integer b(-42);
        integer zero;
        REQUIRE(POZ_Z_D(a) == IntegerState::Positive);
        REQUIRE(POZ_Z_D(b) == IntegerState::Negative);
        REQUIRE(POZ_Z_D(zero) == IntegerState::Zero);
    }
#endif

#ifdef SUB_ZZ_Z_CPP
    SECTION("SUB_ZZ_Z [вычитание]") {
        integer a(42);
        integer b(21);
        integer c(-21);
        integer zero;
        REQUIRE(SUB_ZZ_Z(a, a) == zero);
        REQUIRE(SUB_ZZ_Z(b, c) == a);
    }
#endif
}

TEST_CASE("Рациональные числа", "[fractional]") {
#ifdef RED_Q_Q_CPP
    SECTION("RED_Q_Q [сокращение дроби]") {
        fraction a("437/506");
        fraction b("19/22");
        REQUIRE(RED_Q_Q(a) == b);

        a = fraction("-272/128");
        b = fraction("-17/8");
        REQUIRE(RED_Q_Q(a) == b);

        a = fraction("1/3");
        REQUIRE(RED_Q_Q(a) == a);

        a = fraction("-62/1");
        REQUIRE(RED_Q_Q(a) == a);
    }
#endif  // RED_Q_Q_CPP

#ifdef INT_Q_B_CPP
    SECTION("INT_Q_B [проверка на целое]") {
        fraction a(-8);
        REQUIRE(INT_Q_B(a));

        a = fraction("24/6");
        REQUIRE(INT_Q_B(a));

        a = fraction("7/6");
        REQUIRE_FALSE(INT_Q_B(a));

        a = fraction("-15/25");
        REQUIRE_FALSE(INT_Q_B(a));
    }
#endif  // INT_Q_B_CPP

#ifdef TRANS_Z_Q_CPP
    SECTION("TRANS_Z_Q [преобразование целого в дробное]") {
        integer a(-42);
        fraction b(-42);
        REQUIRE(TRANS_Z_Q(a) == b);

        a = integer(5);
        b = fraction(5);
        REQUIRE(TRANS_Z_Q(a) == b);
    }
#endif  // TRANS_Z_Q_CPP

#ifdef TRANS_Q_Z_CPP
    SECTION("TRANS_Q_Z [преобразование дробного в целое]") {
        fraction a(-42);
        integer b(-42);
        REQUIRE(TRANS_Q_Z(a) == b);

        a = fraction(5);
        b = integer(5);
        REQUIRE(TRANS_Q_Z(a) == b);

        a = fraction("9/3");
        b = integer(3);
        REQUIRE(TRANS_Q_Z(a) == b);

        a = fraction("-100/50");
        b = integer(-2);
        REQUIRE(TRANS_Q_Z(a) == b);
    }
#endif  // TRANS_Q_Z_CPP

#ifdef  ADD_QQ_Q_CPP
    SECTION("ADD_QQ_Q [сложение дробей]") {
        fraction a("5/8");
        fraction b("9/24");
        fraction c("24/24");  // fraction c("1/1");
        REQUIRE(ADD_QQ_Q(a, b) == c);

        a = fraction("5/12");
        b = fraction("-3/4");
        c = fraction("-4/12");  // c = fraction("-1/3");
        REQUIRE(ADD_QQ_Q(a, b) == c);
    }
#endif  // ADD_QQ_Q_CPP

#ifdef SUB_QQ_Q_CPP
    SECTION("SUB_QQ_Q [вычитание дробей]") {
        fraction a("5/12");
        fraction b("-3/4");
        fraction c("14/12");  // fraction c("7/6");
        REQUIRE(SUB_QQ_Q(a, b) == c);

        a = fraction("40/63");
        b = fraction("5/18");
        c = fraction("45/126");  // c = fraction("5/14");
        REQUIRE(SUB_QQ_Q(a, b) == c);
    }
#endif  // SUB_QQ_Q_CPP

#ifdef MUL_QQ_Q_CPP
    SECTION("MUL_QQ_Q [умножение дробей]") {
        fraction a("6/14");
        fraction b("7/5");
        fraction c("6/10");
        REQUIRE(MUL_QQ_Q(a, b) == c);

        a = fraction("-3/11");
        b = fraction("13/18");
        c = fraction("-13/66");
        REQUIRE(MUL_QQ_Q(a, b) == c);

        a = fraction("-2/5");
        b = fraction("-15/16");
        c = fraction("3/8");
        REQUIRE(MUL_QQ_Q(a, b) == c);
    }
#endif  // MUL_QQ_Q_CPP

#ifdef DIV_QQ_Q_CPP
    SECTION("DIV_QQ_Q [деление дробей]") {
        fraction a("6/14");
        fraction b("5/7");
        fraction c("6/10");
        REQUIRE(DIV_QQ_Q(a, b) == c);

        a = fraction("-3/11");
        b = fraction("18/13");
        c = fraction("-13/66");
        REQUIRE(DIV_QQ_Q(a, b) == c);

        a = fraction("-2/5");
        b = fraction("-16/15");
        c = fraction("3/8");
        REQUIRE(DIV_QQ_Q(a, b) == c);
    }
#endif  // DIV_QQ_Q_CPP
}

TEST_CASE("Полиномы", "[polynom]") {

#ifdef DER_P_P_CPP
    SECTION("DER_P_P [производная]") {
        polynom p1, pR;

        p1 = polynom({ 5, 9, 4, 7, 0, 4, -15 });
        pR = polynom({ 30, 45, 16, 21, 0, 4 });
        REQUIRE(DER_P_P(p1) == pR);
        REQUIRE_FALSE(DER_P_P(p1) == p1);

        p1 = polynom({ 9 });
        pR = polynom({ 0 });
        REQUIRE(DER_P_P(p1) == pR); // (9)' = 0
        REQUIRE(DER_P_P(pR) == pR); // (0)' = 0		
    }
#endif  // DER_P_P_CPP

#ifdef ADD_PP_P_CPP
    SECTION("ADD_PP_P [сложение]") {
        polynom p1, p2, pR;

        p1 = { 7, 8, -9 };
        p2 = { 14, 0, 7, 4 };
        pR = { 14, 7, 15, -5 };
        REQUIRE(ADD_PP_P(p1, p2) == pR);
        REQUIRE(ADD_PP_P(p2, p1) == pR);

        // сложение с 0
        p2 = { 0 };
        REQUIRE(ADD_PP_P(p1, p2) == p1);
        REQUIRE(ADD_PP_P(p2, p1) == p1);

    }
#endif  // ADD_PP_P_CPP

#ifdef DEG_P_N_CPP
    SECTION("DEG_P_N [степень]") {
        polynom p1, p2;
        natural pN;

        p1 = { 8, 7, 15, 0, 56, 96, 0, 0, 4, 78, 45, 0, 69, 3, 45, 0, 1 };
        pN = { _1, _6 };
        p2 = { 8, 5, 9, 0, 0, 0, 1, 5, 0, 4 };
        REQUIRE(DEG_P_N(p1) == pN);
        REQUIRE_FALSE(DEG_P_N(p2) == pN);

        // нулевой полином
        p1 = { 0 };
        pN = { 0 };
        REQUIRE(DEG_P_N(p1) == pN);
    }
#endif  // DEG_P_N_CPP

#ifdef SUB_PP_P_CPP
    SECTION("SUB_PP_P [вычитание]") {
        polynom p1, p2, pR;

        // обычное вычитание
        p1 = { 4, 0, 3, -6, 0 };
        p2 = { 9, 0, 0, -2, 3, -9 };
        pR = { -9, 4, 0, 5, -9, 9 };
        REQUIRE(SUB_PP_P(p1, p2) == pR);
        REQUIRE_FALSE(SUB_PP_P(p2, p1) == pR);

        // один из полиномов 0
        p1 = { 0 };
        p2 = { 9, 0, 0, -2, 3, -9 };
        pR = { -9, 0, 0, 2, -3, 9 };
        REQUIRE(SUB_PP_P(p1, p2) == pR);
        REQUIRE_FALSE(SUB_PP_P(p2, p1) == pR);

        // р1 = р2
        p1 = p2 = { 1, 2, 3, 4, 5, 6 };
        pR = { 0, 0, 0, 0, 0, 0 };
        REQUIRE(SUB_PP_P(p1, p2) == pR);

        // х^2
        p1 = { 0, 0, 0, -2, 0, 0 };
        p2 = { 9, 5, 6, -2, 3, -9 };
        pR = { 9, 5, 6, 0, 3, -9 };
        REQUIRE(SUB_PP_P(p2, p1) == pR);
        REQUIRE_FALSE(SUB_PP_P(p1, p2) == pR);
    }
#endif  // SUB_PP_P_CPP

#ifdef MUL_PQ_P_CPP
    SECTION("MUL_PQ_P [умножение на рациональное число]") {
        polynom p1, pR;
        fraction pF(111), pF_1(1), pF_0(0);

        p1 = { 1, 2, 3, 4, 5, 6, 0, 0, 9 };
        pR = { 111, 222, 333, 444, 555, 666, 0, 0, 999 };

        REQUIRE(MUL_PQ_P(p1, pF) == pR); // *111/1
        REQUIRE(MUL_PQ_P(p1, pF_1) == p1); // *1/1
        REQUIRE_FALSE(MUL_PQ_P(p1, pF_0) == p1); // *0/1
    }
#endif  // MUL_PQ_P_CPP

#ifdef MUL_Pxk_P_CPP
    SECTION("MUL_Pxk_P [умножение на х^k]") {
        polynom p1, pR;
        unsigned k = 0;

        // *x^0
        p1 = { 1, 2, 3, 4 };
        REQUIRE(MUL_Pxk_P(p1, k) == p1);

        // *x^1
        k = 1;
        pR = { 1, 2, 3, 4, 0 };
        REQUIRE(MUL_Pxk_P(p1, k) == pR);

        // *x^4
        k = 4;
        pR = { 1, 2, 3, 4, 0, 0, 0, 0 };
        REQUIRE(MUL_Pxk_P(p1, k) == pR);
    }
#endif  // MUL_Pxk_P_CPP

#ifdef LED_P_Q_CPP
    SECTION("LED_P_Q [старший коэффициент]") {
        polynom p1;	fraction pF(4);

        p1 = { 4, 3, 2, 1, 7 };
        REQUIRE(LED_P_Q(p1) == pF);

        p1 = { 0, 0, 5, 9, 7, 8 };
        fraction pF_g;
        REQUIRE_FALSE(LED_P_Q(p1) == pF_g);
    }
#endif  // LED_P_Q_CPP

/*#ifdef FAC_P_PQ_CPP
    SECTION(" FAC_P_PQ [степень]") {
    }
#endif  // FAC_P_PQ_CPP*/

#ifdef MUL_PP_P_CPP
    SECTION("MUL_PP_P [умножение полиномов]") {
        polynom p1, p2, pR;

        p1 = { 1, 2, 3, 2, 3, 1 };
        p2 = { 2, 1 };
        pR = { 2, 5, 8, 7, 8, 5, 1 };
        REQUIRE(MUL_PP_P(p1, p2) == pR);
        REQUIRE(MUL_PP_P(p2, p1) == pR);

        p2 = { 0 }; // *0
        REQUIRE(MUL_PP_P(p1, p2) == p2);
        REQUIRE(MUL_PP_P(p2, p1) == p2);

        p1 = p2; // 0*0
        REQUIRE(MUL_PP_P(p1, p2) == p1);

        p2 = { 1 }; // *1
        REQUIRE(MUL_PP_P(p1, p2) == p1);

        p1 = p2; // 1*1
        REQUIRE(MUL_PP_P(p1, p2) == p1);
    }
#endif  // MUL_PP_P_CPP
    
#ifdef DIV_PP_P_CPP
    SECTION("DIV_PP_P [деление полиномов (частное)]") {
        polynom p1, p2, pR;

        p1 = { 3, 2, 0, 1, 1, 1 };
        p2 = { 1, 2, 1, 0 };
        pR = { 3, -4, 5 };
        REQUIRE(DIV_PP_P(p1, p2) == pR);

        // деление полинома на самого себя
        p1 = { 1, 2, 1, 0 };
        p2 = { 1, 2, 1, 0 };
        pR = { 1 };
        REQUIRE(DIV_PP_P(p1, p2) == pR);

        // деление на 0
        p1 = { 1, 2, 1, 0 };
        p2 = { 0 };
        REQUIRE_THROWS(DIV_PP_P(p1, p2));

        // deg p2 > deg p1
        p2 = { 3, 2, 0, 1, 1, 1 };
        p1 = { 1, 2, 1, 0 };
        pR = { 0 };
        REQUIRE(DIV_PP_P(p1, p2) == pR);

        // деление на 1
        p1 = { 1, 2, 1, 0 };
        p2 = { 1 };
        REQUIRE(DIV_PP_P(p1, p2) == p1);

        //деление с "фуфу" коэффициентами
        p1 = { 5, 3, 1 };
        p2 = { 2, -1 };
        pR = { fraction("5/2"), fraction("11/4") };
        REQUIRE(DIV_PP_P(p1, p2) == pR);
    }
#endif  // DIV_PP_P_CPP
    
#ifdef MOD_PP_P_CPP
    SECTION("MOD_PP_P [деление полиномов (остаток)]") {
        polynom p1, p2, pR;

        p1 = { 3, 2, 0, 1, 1, 1 };
        p2 = { 1, 2, 1, 0 };
        pR = { -5, -4, 1 };
        REQUIRE(MOD_PP_P(p1, p2) == pR);

        // деление полинома на самого себя
        p1 = { 1, 2, 1, 0 };
        p2 = { 1, 2, 1, 0 };
        pR = { 0 };
        REQUIRE(MOD_PP_P(p1, p2) == pR);

        // деление на 1
        p1 = { 1, 2, 1, 0 };
        p2 = { 1 };
        pR = { 0 };
        REQUIRE(MOD_PP_P(p1, p2) == pR);

        p1 = { 2, -11, 19, -13, 3 };
        p2 = { 2, -3, 1 };
        pR = { 0 };
        REQUIRE(MOD_PP_P(p1, p2) == pR);

        //деление с "фуфу" коэффициентами
        p1 = { 5, 3, 1 };
        p2 = { 2, -1 };
        pR = { fraction("15/4") };
        REQUIRE(MOD_PP_P(p1, p2) == pR);
    }
#endif  // MOD_PP_P_CPP
}
