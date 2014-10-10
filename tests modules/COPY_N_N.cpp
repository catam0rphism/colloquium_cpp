#include <iostream>
#include <fstream>
#include "../struct.h"
using namespace std;
natural COPY_N_N(const natural); //user function
natural DELZ_N_N(const natural); //для user function
natural NEW_N_N(const natural); //для DELZ_N_N
void DEL_N(const natural); //для DELZ_N_N
bool test(const natural, const natural); //для проверки
#include "../modules/COPY_N_N.cpp" //user function
#include "../modules/DELZ_N_N.cpp" //для user function
#include "../modules/NEW_N_N.cpp" //для DELZ_N_N
#include "../modules/DEL_N.cpp" //для DELZ_N_N
#include "test.cpp" //для проверки

int main()
{
	unsigned short n=1;
	char comment[256];
	fstream file("../tests/COPY_N_N",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while(!file.eof())
	{
		natural x,_x,result,z;
		file>>x.count;
		if (file.eof()) return 0;
		_x.count=x.count;
		x=NEW_N_N(x);
		_x=NEW_N_N(_x);
		for(register unsigned short i=0;i<x.count;i++)
		{
			file>>x.digits[i];
			_x.digits[i]=x.digits[i];
		};
		file>>result.count;
		result=NEW_N_N(result);
		for(register unsigned short i=0;i<result.count;i++)
			file>>result.digits[i];	
		file.ignore();
		file.getline(comment,255);
		file.sync();
		z=DELZ_N_N(x);//user function
		if (!test(x,_x)) //Проверка
		{
			cout<<"Ошибка! Данные, переданные в модуль, были изменены!";
			return 254;
		};
		if (x.digits==z.digits)
		{
			cout<<"Ошибка! Модуль вернул значение, которое было передано в него!";
			return 253;
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
}
