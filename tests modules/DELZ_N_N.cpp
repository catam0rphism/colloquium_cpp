#include <fstream>
#include <iostream>
using namespace std;
#include "../struct.h"
natural NEWN_N_N(natural n); //для user function
natural DELZ_N_N(const natural n); //user function
bool test(const natural, const natural); //для проверки
void DELN_N(natural); //для user function
#include "../Модули/DELZ_N_N.cpp" //user function
#include "../Модули/DELN_N.cpp" //для user function
#include "test.cpp" //для проверки
#include "../Модули/NEWN_N_N.cpp" //для user function
//using namespace std;

int main()
{
	unsigned short n=0;
	fstream file("../Тесты/DELZ_N_N",ios::in);
	if (!file) return 254; //Проверка на существование тестов
	file>>n;
	for(register unsigned short i=1; i<=n; i++)
	{
		natural x,_x,result,z; //Копируем x в _x
		file>>x.count;
		_x.count=x.count;
		x=NEWN_N_N(x);
		_x=NEWN_N_N(_x);
		for(register unsigned short j=0;j<x.count;j++)
		{
			file>>x.digits[j];
			_x.digits[j]=x.digits[j];
		};
		file>>result.count;
		result=NEWN_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		z=DELZ_N_N(x);//user function
		if (!test(x,_x)) return 255; //Проверка на сохранность данных
		if (!test(z/*user function*/,result)) return i;
		DELN_N(x);
		DELN_N(_x);
		DELN_N(z);
		DELN_N(result);
	};
	return 0;
}
