#ifndef STRUCT_H
#define STRUCT_H

#include <vector>

//Натуральное число
struct natural
{
    //Массив чисел
    std::vector<short int>* digits;

    //Количество разрядов в числе
    // TODO: test it
    int count() { return digits->length(); }

    ~natural() {
        digits->clean();
        delete digits;
    }
};
struct integer //Целое число
{
	bool sign; //Знак числа
	natural module; //Модуль целого числа, представленный как натуральное
};
struct fraction //Дробь
{
	integer numerator; //Числитель дроби, представленный как целое число
	natural denominator; //Знаменатель дроби, представленный как натуральное число
};
struct polynom //Многочлен
{    
    std::vector<fraction>* coefficients; //Коэффициенты многочлена, представленные дробью

    //Степень многочлена
    int degree() { return coefficients->length(); }
};

#endif // STRUCT_H
