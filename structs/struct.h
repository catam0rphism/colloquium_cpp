// Copyright 2015 Belkin Dmitriy
#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <iterator>
#include <string>
#include <initializer_list>

#include "./digit.h"
#include "./ordinal.h"
#include "./state.h"

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

    // Контруктор из строки "42" ===> { _2, _4 } т.е. 42
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

    natural(const unsigned &input) : natural() {
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
        while ((digits.back() == _0) && (digits.size() != 1)) {
            digits.pop_back();
        }
    }

    void orderShift(const int& orderCount) {
        int order = orderCount;
        if (order < 0) throw;
        
        while (order --> 0) {
            digits.insert(digits.begin(), _0);
        }
    }

    // Количество значащих разрядов в числе
    // Выделить в отдельную переменную?
    int order() const { // TODO(Belkin Dmitriy): fix zero order
        int k = digits.size();
        while (digits[k-1] == _0 && k > 0) { k--; }
        return k;
    }

    // Вычисляет порядок и уничтожает лишние нули
    int order() {
        reduce();
        int s = digits.size();
        if (s == 1 && digits[0] == _0)
            return 0;
        
        return s;
    }

    natural& operator= (const natural& other) {
        // TODO(Belkin Dmitriy): можно ли оператор ==, который в другом файле
        // if (this == *other) return *this;
        digits = other.digits;
        return *this;
    }

    ~natural() {
        digits.clear();
        // delete digits;
    }

    digit& operator[](const int& digitInd) {
        if (digitInd >= order()) {
            int k = order();
            if (k == 0) k = 0; // wtf omfg  crazy stuff
            while(digitInd >= k) {
                digits.push_back( _0 );
                k++;
            }
        }
        return digits[digitInd];
    }

    digit& operator[](const int& digitInd) const {
        if (digitInd >= order()) {
            return _0;
        }
        return digits[digitInd];
    }

    natural operator + (const natural& other);
    natural operator - (const natural& other);
    natural operator * (const natural& ohter);
    natural operator * (const digit& other);
    natural operator / (const natural& ohter);
    natural operator % (const natural& ohter);

    void operator++( int );
    friend bool operator == (const natural& left, const natural& right);
    friend bool operator <  (const natural& left, const natural& right);
    friend bool operator >  (const natural& left, const natural& right);
    friend bool operator <= (const natural& left, const natural& right);
    friend bool operator >= (const natural& left, const natural& right);

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

	integer operator*(const integer& ohter);

    bool operator==(const integer& other);
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

    bool operator==(const fraction& other);

    fraction operator+(const fraction& other);
    fraction operator-(const fraction& other);
    fraction operator*(const fraction& ohter);
    fraction operator/(const fraction& ohter);
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

    void reduce() {
        int k = coefficients.size()-1;
        natural n_zero;
        natural curr = coefficients[k].numerator.module;
        while (curr == n_zero && k > 0) {
            coefficients.pop_back();
            k--;
            curr = coefficients[k].numerator.module;
        }
    }

    // Степень многочлена
    int degree() const {
        int k = coefficients.size()-1;
        natural n_zero;
        natural curr = coefficients[k].numerator.module;
        while (curr == n_zero && k > 0) {
            k--;
            curr = coefficients[k].numerator.module;
        }
        return k;
    }

    void degreeShift(const unsigned &degreeCount) {
        unsigned order = degreeCount;
        while (order --> 0) {
            coefficients.insert(coefficients.begin(), fraction(0));
        }
    }

    polynom& operator= (const polynom& other) {
        // TODO: проверка самоприсвоения
        coefficients = other.coefficients;
        return *this;
    }

    ~polynom() {
        coefficients.clear();
    }

    fraction& operator[](const int& coeffInd) {
        if (coeffInd > degree()) {
            int k = degree();
            while (coeffInd > k) {
                coefficients.push_back(fraction(0));
                k++;
            }
        }
        return coefficients[coeffInd];
    }

	fraction operator[](const int& coeffInd) const {
		if (coeffInd > degree()) {
			throw std::invalid_argument("No elemet with this index");
			}
		return fraction(coefficients[coeffInd]);
	}

	polynom& operator+=(const polynom& other);

 private:
    // Коэффициенты многочлена в порядке увеличения степени
    // 18x^3 + 4x^2 + 3 <==> { 3, 0, 4, 18 }
    std::vector<fraction> coefficients;
};

#endif  // STRUCT_H
