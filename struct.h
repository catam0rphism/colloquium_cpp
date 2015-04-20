// Copyright 2015 Belkin Dmitriy
#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <iterator>
#include <initializer_list>

enum /* class */ digit: std::int8_t { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
                                        _minDigit = _0, _maxDigit = _9, _NotaDigit = -1 };

// Инкремент ЦИФРЫ. Работает по принципу полного сумматора т.е.
// принимает цифру и перенос предыдущего сложения 
// (если такового нет - false) перенос (overflowFlag) обновляется внутри
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

// складывает 2 цифры. Работает как инкремент.
digit add(const digit &a, const digit &b, bool &overflowFlag) {
    std::int8_t sum = a + b + static_cast<std::int8_t>(overflowFlag);
    // TODO: заменить static_cast на что-то лучшее
    // ибо нефиг складывать bool с всякими int'ами

    overflowFlag = sum > _9;
    return static_cast<digit>(overflowFlag ? sum - 10 : sum);
}

// вычитает из одной цифры другую
// первый аргумент обязательно больше либо равен второму !!
// если это не так, возвращает _NotaDigit т.е. "Не цифра" 
digit sub(const digit &a, const digit &b) {
    if (a < b) { return _NotaDigit;
    } else { return static_cast<digit>(a - b); }
}

// Умножает 2 числа, demolition - аналог флага переполнения
// она прибовляется к результату умножения и, после умножения, 
// cтановится равной цифре которая должна быть прибавленна к следующему разряду
// [в использовании аналогична флагу переполнения]
digit mul(const digit &a, const digit &b, digit& demolition) {
    std::int8_t mulRes = a * b;
    denominator = static_cast<digit>(mulRes / 10);
    
    return static_cast<digit>(mulRes % 10);
}

// Результаты сравнений (меньше, больше, равно)
enum class ordinal: std::int8_t { LT, GT, EQ };

// #яХочуКлассы #нужноБольшеИнкапсуляции
// Натуральное число
struct natural {
    // TODO: Добавить других конструкторов
    natural(): natural({ _0 }) { }  // инициализация нулем
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
