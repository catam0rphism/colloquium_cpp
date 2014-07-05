#include <fstream>
#include "../struct.h"
natural MUL_ND_N(const natural, const unsigned short); //user function
natural ADD_NN_N(const natural, const natural); //для user function
bool NZER_N_B(const natural); //для COM_NN_D
unsigned short COM_NN_D(const natural, const natural); //для ADD_NN_N
natural DELZ_N_N(const natural); //для NZER_N_B
natural NEWN_N_N(natural); //для DELZ_N_N
void DELN_N(natural); //для DELZ_N_N
natural MUL_Nk_N(const natural, const unsigned short); //для user function
bool test(const natural, const natural); //для проверки
#include "../Модули/MUL_ND_N.cpp" //user function
#include "../Модули/ADD_NN_N.cpp" //для user function
#include "../Модули/NZER_N_B.cpp" //для COM_NN_D
#include "../Модули/DELZ_N_N.cpp" //для NZER_N_B
#include "../Модули/NEWN_N_N.cpp" //для DELZ_N_N
#include "../Модули/DELN_N.cpp" //для DELZ_N_N
#include "../Модули/MUL_Nk_N.cpp" //для user function
#include "../Модули/COM_NN_D.cpp" //для ADD_NN_N
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../Тесты/MUL_ND_N",ios::in);
	unsigned short n;
	if (!file) return 254; //Проверка на существование тестов
	file>>n;
	for(register unsigned short i=1;i<=n;i++)
	{
		natural x,_x,z,result; //Копируем x в _x
		unsigned short d;
		file>>x.count;
		_x.count=x.count;
		x=NEWN_N_N(x);
		_x=NEWN_N_N(_x);
		for(register unsigned short j=0;j<x.count;j++)
		{
			file>>x.digits[j];
			_x.digits[j]=x.digits[j];
		};
		file>>d>>result.count;
		result=NEWN_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		z=MUL_ND_N(x,d);//user function
		if (!test(x,_x)) return 255; //Проверка на сохранность исходных данных
		if (!test(z/*user function*/,result)) return i;
		DELN_N(x);
		DELN_N(_x);
		DELN_N(z);
		DELN_N(result);
	};
	return 0;
};
