// Copyright 2015 Belkin Dmitriy
#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>

#include "ordinal.h"

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
// первый аргумент обязательно больше либо равен второму !!
// если это не так, возвращает _NotaDigit т.е. "Не цифра"
digit sub(const digit &a, const digit &b, bool &insufficienceFlag) {
    digit tmp = a;
    if(insufficienceFlag) { tmp = a - 1; }
    
    if (tmp < b) { return static_cast<digit>(10+a-b); }
    } else { return static_cast<digit>(a - b); }
}

// Умножает 2 числа, demolition - аналог флага переполнения
// она прибовляется к результату умножения и, после умножения,
// cтановится равной цифре которая должна быть прибавленна к следующему разряду
// [в использовании аналогична флагу переполнения]
digit mul(const digit &a, const digit &b, digit& demolition) {
    std::int8_t mulRes = a * b;
    mulRes += demolition;

    demolition = static_cast<digit>(mulRes / 10);

    return static_cast<digit>(mulRes % 10);
}

ordinal ord(const digit &a,const digit &b) {
    if(a == b) { return ordinal::EQ;
    } else if (a > b) { return ordinal::GT;
    } else { return ordinal::LT; }
}

#endif  // DIGIT_H
