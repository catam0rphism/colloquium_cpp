// Copyright 2015 Belkin Dmitriy
#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <iterator>
#include <initializer_list>

enum /* class */ digit: std::int8_t { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
                                        _minDigit = _0, _maxDigit = _9 };

static void inc(digit &a, bool &overflowFlag) {
    if ((!overflowFlag && a == _maxDigit) ||
        (overflowFlag && a == static_cast<digit>(_maxDigit - 1)) {
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

static digit add(const digit &a, const digit &b, bool &overflowFlag) {
    std::int8_t sum = a + b + static_cast<std::int8_t>(overflowFlag);
    // ибо нефиг складывать bool с всякими int'фми

    overflowFlag = sum > _9;

    return static_cast<digit>(overflowFlag ? sum - 10 : sum);
}

// #яХочуКлассы #нужноБольшеИнкапсуляции
// Натуральное число
struct natural {
    // TODO: Добавить других конструкторов
    natural() { }
    natural(const natural& number) {
        this->digits = number.digits;  // vector copy constructor
    }

    natural(std::initializer_list<digit> digits) {
        std::vector<digit> tmp(digits);

        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            this->digits.push_back(*it);
            it++;
        }
    }

    // Массив цифр от младших разрядов к старшим
    // Число 9426 будет представленно как { 6, 2, 4, 9 }
    std::vector<digit> digits;

    // Количество разрядов в числе
    // Issue #1
    // Выделить в отдельную переменную?
    int order() const { return digits.size(); }

    natural& operator= (const natural& other) {
        // TODO: проверка самоприсвоения
        digits = other.digits;
        return *this;
    }

    ~natural() {
        digits.clear();
        // delete digits;
    }

    // TODO: переопределить операторы
};

// Целое число
struct integer {
    bool sign;
    natural module;
};

// Рациональное число
struct fraction {
    //Числитель дроби
    integer numerator;
    //Знаменатель дроби
    natural denominator;
};

// Многочлен
struct polynom {
    polynom() { }
    polynom(const polynom& other) {
        this->coefficients = other.coefficients;
    }

    polynom(std::initializer_list<fraction> coefficients) {
        std::vector<fraction> tmp(coefficients);

        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            this->coefficients.push_back(*it);
            it++;
        }
    }

    // Коэффициенты многочлена в порядке увеличения степени
    // 18x^3 + 4x^2 + 3 <==> { 3, 0, 4, 18 }
    std::vector<fraction> coefficients;

    // Степень многочлена
    int degree() { return coefficients.size(); }

    polynom& operator= (const polynom& other) {
        // TODO: проверка самоприсвоения
        coefficients = other.coefficients;
        return *this;
    }

    ~polynom() {
        coefficients.clear();
        // delete digits;
    }
};

#endif  // STRUCT_H
