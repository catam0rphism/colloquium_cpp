#include <fstream>
#include <iostream>
using namespace std;
#include "../struct.h"
integer TRANS_N_Z(const natural); //user function
natural COPY_N_N(const natural); //для user function
integer NEW_Z_Z(integer); //для user function
void DEL_Z(integer); //для user function
natural DELZ_N_N(const natural); //для user function
natural NEW_N_N(natural); //для NEW_Z_Z
void DEL_N(natural); //для DEL_Z
bool test(const integer, const integer); //для проверки
#include "../modules/TRANS_N_Z.cpp" //user function
#include "../modules/COPY_N_N.cpp" //для user function
#include "../modules/NEW_Z_Z.cpp" //для user function
#include "../modules/DEL_Z.cpp" //для user function
#include "../modules/DELZ_N_N.cpp" //для user function
#include "../modules/NEW_N_N.cpp" //для NEW_Z_Z
#include "../modules/DEL_N.cpp" //для DEL_N
#include "test.cpp" //для проверки

int main()
{
	unsigned short n=1;
	char comment[256];
	fstream file("../tests/TRANS_N_Z",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		natural x,_x; //Копируем x в _x
		integer result,z; //
		file>>x.count;
		if (file.eof()) return 0;
		_x.count=x.count;
		x=NEW_N_N(x);
		_x=NEW_N_N(_x);
		for(register unsigned short j=0;j<x.count;j++)
		{
			file>>x.digits[j];
			_x.digits[j]=x.digits[j];
		};
		file>>result.sign>>result.module.count;
		result=NEW_Z_Z(result);
		for(register unsigned short j=0;j<result.module.count;j++)
			file>>result.module.digits[j];
		file.ignore();
		file.getline(comment,255);
		file.sync();
		z=TRANS_N_Z(x);//user function
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
		DEL_Z(z);
		DEL_Z(result);
		n++;
	};
	return 0;
}
