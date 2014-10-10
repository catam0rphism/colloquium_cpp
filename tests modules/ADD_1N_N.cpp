#include <fstream>
#include <iostream>
#include "../struct.h"
natural DELZ_N_N(const natural, const natural); //для NZER_N_B
void DEL_N(natural); //для DELZ_N_N
natural NEW_N_N(natural); //для DELZ_N_N
natural ADD_1N_N(const natural); //user function
natural COPY_N_N(const natural); //для user function
bool test(const unsigned short, const unsigned short); //для проверки
bool NZER_N_B(const natural); //для user function
#include "../modules/DELZ_N_N.cpp" //для NZER_N_B
#include "../modules/DEL_N.cpp" //для DELZ_N_N
#include "../modules/NEW_N_N.cpp" //для DELZ_N_N
#include "../modules/ADD_1N_N.cpp" //user function
#include "../modules/NZER_N_B.cpp" //для user function
#include "../modules/COPY_N_N.cpp" //для user function
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../tests/ADD_1N_N",ios::in);
	unsigned short n=1;
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		natural x,_x,z,result; //Копируем x в _x
		char comment[256];
		file>>x.count;
		if (file.eof()) return 0;
		x=NEW_N_N(x);
		for(register unsigned short j=0;j<x.count;j++)
			file>>x.digits[j];
		_x=COPY_N_N(x);
		file>>result.count;
		result=NEW_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		file.ignore();
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		z=ADD_1N_N(x); //user function
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
		DEL_N(x);
		DEL_N(_x);
		DEL_N(z);
		DEL_N(result);
		n++;
	};
	return 0;
};
