#include <fstream>
#include <iostream>
#include "../struct.h"
bool NZER_N_B(const natural); //user function
natural NEWN_N_N(const natural); //для DELZ_N_N
natural DELZ_N_N(natural); //для user function
void DELN_N(natural); //для DELZ_N_N
bool test(const bool, const bool); //для проверки
#include "../modules/NZER_N_B.cpp" //user function
#include "../modules/NEWN_N_N.cpp" //для DELZ_N_N
#include "../modules/DELN_N.cpp" //для DELZ_N_N
#include "../modules/DELZ_N_N.cpp" //для user function
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../tests/NZER_N_B",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	unsigned short n=1;
	while (!file.eof())
	{
		natural x,_x; //Копируем x в _x
		bool result,z;
		char comment[256];
		file>>x.count;
		if (file.eof()) return 0;
		_x.count=x.count;
		x=NEWN_N_N(x);
		_x=NEWN_N_N(_x);
		for(register unsigned short i=0;i<x.count;i++)
		{
			file>>x.digits[i];
			_x.digits[i]=x.digits[i];
		};
		file>>result;
		file.ignore();
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		z=NZER_N_B(x); //user function
		if (!test(x,_x)) //Проверка на сохранность данных
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
		n++;
	};
	return 0;
};
