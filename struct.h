struct natural //Натуральное число
{
	unsigned short int count; //Количество цифр в числе
	unsigned short int *digits; //Массив чисел
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
	unsigned short degree; //Степень многочлена
	fraction *coefficients; //Коэффициенты многочлена, представленные дробью
};
