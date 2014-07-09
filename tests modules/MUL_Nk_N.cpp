#include <fstream>
#include <iostream>
#include "../struct.h"
natural DELZ_N_N(const natural, const natural); //для NZER_N_B
void DELN_N(natural); //для DELZ_N_N
natural NEWN_N_N(natural); //для DELZ_N_N
natural MUL_Nk_N(const natural, const natural); //user function
bool test(const unsigned short, const unsigned short); //для проверки
bool NZER_N_B(const natural); //для user function
#include "../modules/DELZ_N_N.cpp" //для NZER_N_B
#include "../modules/DELN_N.cpp" //для DELZ_N_N
#include "../modules/NEWN_N_N.cpp" //для DELZ_N_N
#include "../modules/MUL_Nk_N.cpp" //user function
#include "../modules/NZER_N_B.cpp" //для user function
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../tests/MUL_Nk_N",ios::in);
	unsigned short n=1;
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while(!file.eof())
	{
		natural x,_x,z,result; //Копируем x в _x
		char comment[256];
		unsigned short k;
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
		file>>k>>result.count;
		result=NEWN_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		file.ignore();
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		z=MUL_Nk_N(x,k);//user function
		if (!test(x,_x)) //Проверка на сохранность исходных данных
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
};
