// Copyright 2015 Belkin Dmitriy
#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <initializer_list>

// #яХочуКлассы #нужноБольшеИнкапсуляции
// Натуральное число
struct natural {
    // TODO: Добавить других конструкторов
    natural() { }
    natural(std::initializer_list<short> digits) {
        for (int* argPtr = digits.end(); argPtr != digits.begin(); argPtr--) {
            this->digit.push_back(&argPtr);
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

// Посмотреть на это все позже =)
// struct integer //Целое число
// {
// 	bool sign; //Знак числа
// 	natural module; //Модуль целого числа, представленный как натуральное
// };
// struct fraction //Дробь
// {
// 	integer numerator; //Числитель дроби, представленный как целое число
// 	natural denominator; //Знаменатель дроби, представленный как натуральное число
// };
// struct polynom //Многочлен
// {    
//     std::vector<fraction>* coefficients; //Коэффициенты многочлена, представленные дробью

//     //Степень многочлена
//     int degree() { return coefficients->length(); }
// };

#endif  // STRUCT_H
