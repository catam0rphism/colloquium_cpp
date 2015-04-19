// Copyright 2015 Belkin Dmitriy
#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <iterator>
#include <initializer_list>

// #яХочуКлассы #нужноБольшеИнкапсуляции
// Натуральное число
struct natural {
    // TODO: Добавить других конструкторов
    natural() { }
    natural(const natural& number) {
        this->digits = number.digits;  // vector copy constructor
    }
    
    natural(std::initializer_list<short> digits) {
        std::vector<short> tmp(digits);

        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            this->digits.push_back(*it);
            it++;
        }
    }

    // Массив цифр от младших разрядов к старшим
    // Число 9426 будет представленно как { 6, 2, 4, 9 }
    std::vector<short> digits;

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
        this->polynom = other.polynom;
    }
    
    polynom(std::initializer_list<fraction> coefficients) {
        std::vector<fraction> tmp(coefficients);

        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            this->fraction.push_back(*it);
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
