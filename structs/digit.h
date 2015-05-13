// Copyright 2015 Belkin Dmitriy
#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>

#include "ordinal.h"

#define DEBUG_MODE

// Это наши цифры
enum /* class */ digit: std::int8_t { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
                            _minDigit = _0, _maxDigit = _9, _NotaDigit = -1 };

std::ostream& operator<<(std::ostream &os, const digit &Digit) {
    os << static_cast<int>(Digit);
    return os;
}

// Инкремент ЦИФРЫ. Работает по принципу полного сумматора т.е.
// принимает цифру и перенос предыдущего сложения 
// перенос (overflowFlag) обновляется внутри
// функции
void inc(digit &a, bool &overflowFlag) {
    if ((!overflowFlag && a == _maxDigit) ||
        (overflowFlag && a == static_cast<digit>(_maxDigit - 1))) {
        overflowFlag = true;
        a = _0;
    } else if (overflowFlag && a == _maxDigit) {
        overflowFlag = true;
        a = _1;
    } else {  // нет переполнения
        overflowFlag = false;
        std::int8_t inc_a = a;
        inc_a++;
        a = static_cast<digit>(inc_a);
    }
}

// складывает 2 цифры. Работает как инкремент т.е. принимает перенос предыдущей операции
// и обновляет его
digit add(const digit &a, const digit &b, bool &overflowFlag) {
    // TODO: заменить static_cast на что-то лучшее
    std::int8_t sum = a + b + static_cast<std::int8_t>(overflowFlag);
    // ибо нефиг складывать bool с всякими int'ами

    overflowFlag = sum > _9;
    return static_cast<digit>(overflowFlag ? sum - 10 : sum);
}

// вычитает из одной цифры другую
// insufficienceFlag - флаг недозаполнености (т.е. перенос при вычитании)
digit sub(const digit &a, const digit &b, bool &insufficienceFlag) {
    std::int8_t tmp = a;
    if(insufficienceFlag) { tmp = a - 1; }
    
    insufficienceFlag = false;
    if (tmp < b) {
        insufficienceFlag = true;
        return static_cast<digit>(10 + tmp - b);
    } else { return static_cast<digit>(tmp - b); }
}

// Умножает 2 числа, demolition - аналог флага переполнения
// она прибавляется к результату умножения и после умножения
// cтановится равной цифре, которая должна быть прибавлена к следующему разряду
// [в использовании аналогична флагу переполнения]
digit mul(const digit &a, const digit &b, digit& demolition) {
    std::int8_t mulRes = a * b;
    mulRes += demolition;

    demolition = static_cast<digit>(mulRes / 10);

    return static_cast<digit>(mulRes % 10);
}

ordinal ord(const digit &a, const digit &b) {

   #ifdef DEBUG_MODE
   std::cout << "EQ" << std::endl;
   #endif  // DEBUG_MODE

    if (a == b) { return ordinal::EQ;        
    } else if (a > b) { 

        #ifdef DEBUG_MODE
        std::cout << "GT" << std::endl;
        #endif  // DEBUG_MODE
        
        return ordinal::GT;
    } else {

        #ifdef DEBUG_MODE
        std::cout << "LT" << std::endl;
        #endif  // DEBUG_MODE
        
     return ordinal::LT; }
}

#endif  // DIGIT_H
