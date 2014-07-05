#include <fstream>
#include "../struct.h"
natural DELZ_N_N(const natural, const natural); //для NZER_N_B
void DELN_N(natural); //для DELZ_N_N
natural NEWN_N_N(natural); //для DELZ_N_N
natural MUL_Nk_N(const natural, const natural); //user function
bool test(const unsigned short, const unsigned short); //для проверки
bool NZER_N_B(const natural); //для user function
#include "../Модули/DELZ_N_N.cpp" //для NZER_N_B
#include "../Модули/DELN_N.cpp" //для DELZ_N_N
#include "../Модули/NEWN_N_N.cpp" //для DELZ_N_N
#include "../Модули/MUL_Nk_N.cpp" //user function
#include "../Модули/NZER_N_B.cpp" //для user function
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../Тесты/MUL_Nk_N",ios::in);
	unsigned short n;
	if (!file) return 254; //Проверка на существование тестов
	file>>n;
	for(register unsigned short i=1;i<=n;i++)
	{
		natural x,_x,z,result; //Копируем x в _x
		unsigned short k;
		file>>x.count;
		_x.count=x.count;
		x=NEWN_N_N(x);
		_x=NEWN_N_N(_x);
		for(register unsigned short j=0;j<x.count;j++)
		{
			file>>x.digits[j];
			_x.digits[j]=x.digits[j];
		};
		file>>k>>result.count;
		result=NEWN_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		z=MUL_Nk_N(x,k);//user function
		if (!test(x,_x)) return 255; //Проверка на сохранность исходных данных
		if (!test(z/*user function*/,result)) return i;
		DELN_N(x);
		DELN_N(_x);
		DELN_N(z);
		DELN_N(result);
	};
	return 0;
};
