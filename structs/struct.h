// Copyright 2015 Belkin Dmitriy
#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <iterator>
#include <string>
#include <initializer_list>

#include "./digit.h"
#include "./ordinal.h"

// #яХочуКлассы #нужноБольшеИнкапсуляции
// Натуральное число
struct natural {
    natural(): natural({ _0 }) { }  // инициализация нулем
    natural(const natural& number) {
        this->digits = number.digits;  // vector copy constructor
    }

    // Конструктор из списка цифр в нормальном порядке: { _3, _4, _0 } <===> 340
    natural(std::initializer_list<digit> digits) {
        std::vector<digit> tmp(digits);

        // Костыль с reverse iterator
        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            this->digits.push_back(*it);
            it++;
        }
    }

    // Контруктор из строки "42" <===> 42
    natural(const std::string &input) {
      auto it = input.rbegin();
      while (it != input.rend()) {
        if (('0' <= *it) && (*it <= '9')) {
            this->digits.push_back(static_cast<digit>(*it - '0'));
            it++;
        } else {
            // if (*it == std::string::npos) return;
            throw;
              // TODO(timecatler): exception
        }
      }
    }

    natural(const unsigned &input) {
        if (input == 0) return;
        unsigned number = input;
        unsigned i = 0;
        
        digits = std::vector<digit>();

        while (number != 0) {
            digits.push_back(static_cast<digit>(number % 10));
            number /= 10;
            i++;
        }
    }

    // Уничтожитель незначащих нулей
    void reduce() {
        while ((digits.back() == _0) && (digits.size() != 0)) {
            digits.pop_back();
        }
    }

    void orderShift(const unsigned &orderCount) {
        unsigned order = orderCount;
        while (order --> 0) {
            digits.insert(digits.begin(), _0);
        }
    }

    // Количество значащих разрядов в числе
    // Выделить в отдельную переменную?
    int order() const {
        int k = digits.size();
        while (digits[k - 1] == _0 && k > 0) { k--; }
        return k;
    }

    natural& operator= (const natural& other) {
        if (*this == other) return *this;
        digits = other.digits;
        return *this;
    }

    ~natural() {
        digits.clear();
        // delete digits;
    }

    // TODO: переопределить операторы
    digit& operator[](const int& digitInd) {
        if (digitInd >= order()) {
            int k = order();
            while(digitInd >= k) {
                digits.push_back( _0 );
                k++;
            }
        }
        return digits[digitInd];
    }

    natural operator+(const natural& other);
    natural operator-(const natural& other);

    void operator++( int );
    bool operator==(const natural& other);
    bool operator<(const natural &other);
    bool operator>(const natural &other);
    bool operator<=(const natural &other);
    bool operator>=(const natural &other);

 private:
    // Массив цифр от младших разрядов к старшим
    // Число 9426 будет представленно как { 6, 2, 4, 9 }
    std::vector<digit> digits;
};

// Целое число
struct integer {
    integer() { isPositive = true; module = natural(); }
    integer(const int& a) {
        isPositive = a >= 0;
        module = natural(abs(a));
    }
    integer(const natural &natural) : integer() {
        module = natural;
    }
    integer(const std::string &input) {
        std::string cinput = input;
        if (cinput[0] == '-') {
            isPositive = false;
            cinput.erase(cinput.begin());
        } else {
            if (cinput[0] == '+') {
                cinput.erase(cinput.begin());
            }
        }
        module = natural(cinput);
    }

    bool isPositive;
    natural module;
};

// Рациональное число
struct fraction {
    // Создаёт дробь 0/1
    fraction() {
        numerator = integer();
        denominator = natural({ _1 });
    }
    explicit fraction(const int& a) : fraction() {
        numerator = integer(a);
    }
    // Поведение следующего конструктора при неверных
    // входных данных не детерменировано.
    // Создаёт рациональное по строке вида "numerator/denominator"
    explicit fraction(const std::string &input) {
        std::string s_numerator;
        auto it = input.begin();
        while (*it != '/') {
            s_numerator.push_back(*it);
            it++;
        }
        numerator = integer(s_numerator);
        it++;
        std::string s_denominator;
        while (it != input.end()) {
            s_denominator.push_back(*it);
            it++;
        }
        denominator = natural(s_denominator);
    }
    //Числитель дроби
    integer numerator;
    //Знаменатель дроби
    natural denominator;
};

// Многочлен
struct polynom {
    polynom(): polynom({ fraction(0) }) { }
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

#warning TODO: reduce!!!!
    void reduce() {
        // while ((coefficients.back() == fraction(0))
        //     && (coefficients.size() != 0)) {
        //     coefficients.pop_back();
        // }
    }

#warning TODO: degree!!!!
    // Степень многочлена
    int degree() const {
        int k = coefficients.size();
        // while (coefficients[k - 1] == 0 && k > 0) { k--; }
        return k;
    }

#warning TODO: degreeShift!!!!
    void degreeShift(const unsigned &degreeCount) {
        // unsigned order = degreeCount;
        // while (order --> 0) {
        //     coefficients.insert(coefficients.begin(), 0);
        // }
    }

    polynom& operator= (const polynom& other) {
        // TODO: проверка самоприсвоения
        coefficients = other.coefficients;
        return *this;
    }

    ~polynom() {
        coefficients.clear();
    }

#warning TODO: index!!!!
    fraction& operator[](const int& coeffInd) {
        if (coeffInd >= degree()) {
            int k = degree();
            while(coeffInd >= k) {
                // coefficients.push_back( 0 );
                k++;
            }
        }
        return coefficients[coeffInd];
    }

 private:
    // Коэффициенты многочлена в порядке увеличения степени
    // 18x^3 + 4x^2 + 3 <==> { 3, 0, 4, 18 }
    std::vector<fraction> coefficients;

};

#endif  // STRUCT_H
