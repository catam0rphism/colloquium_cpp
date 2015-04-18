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
    natural(std::initializer_list<short> digits) {
        std::vector<short> tmp(digits);

        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            this->digits.push_back(*it);
            it++;
        }
    }

    natural(const natural& number) {
        this->digits = number.digits;  // vector copy constructor
    }

    // Массив цифр от младших разрядов к старшим
    // Число 9426 будет представленно как { 6, 2, 4, 9 }
    std::vector<short> digits;

    // Количество разрядов в числе
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
struct fraction
{
    //Числитель дроби
    integer numerator;
    //Знаменатель дроби
    natural denominator;
};

// Посмотреть на это все позже =)
// struct polynom //Многочлен
// {    
//     std::vector<fraction>* coefficients; //Коэффициенты многочлена, представленные дробью

//     //Степень многочлена
//     int degree() { return coefficients->length(); }
// };

#endif  // STRUCT_H
