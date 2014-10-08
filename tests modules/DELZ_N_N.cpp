#include <fstream>
#include <iostream>
using namespace std;
#include "../struct.h"
natural NEWN_N_N(natural n); //для user function
natural DELZ_N_N(const natural n); //user function
bool test(const natural, const natural); //для проверки
void DELN_N(natural); //для user function
#include "../modules/DELZ_N_N.cpp" //user function
#include "../modules/DELN_N.cpp" //для user function
#include "test.cpp" //для проверки
#include "../modules/NEWN_N_N.cpp" //для user function
//using namespace std;

int main()
{
	unsigned short n=1;
	char comment[256];
	fstream file("../tests/DELZ_N_N",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		natural x,_x,result,z; //Копируем x в _x
		file>>x.count;
		if (file.eof()) return 0;
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
		file.ignore();
		file.getline(comment,255);
		file.sync();
		z=DELZ_N_N(x);//user function
		if (!test(x,_x)) //Проверка
		{
			cout<<"Ошибка! Данные, переданные в модуль, были изменены!";
			return 254;
		};
		if (!test(z/*user function*/,result))
		{
			cout<<"Ошибка в тесте "<<n<<":\n";
			for(register unsigned char i=0;comment[i];i++)
				cout<<comment[i];
			return n;
		};
		DELN_N(x);
		DELN_N(_x);
		DELN_N(z);
		DELN_N(result);
		n++;
	};
	return 0;
}
