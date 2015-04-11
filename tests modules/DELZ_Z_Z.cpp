#include <fstream>
#include <iostream>
using namespace std;
#include "../struct.h"
integer DELZ_Z_Z(integer); //user function
integer NEW_Z_Z(integer); //для user function
void DEL_Z(integer); //для user function
natural DELZ_N_N(const natural); //для user function
natural NEW_N_N(natural); //для NEW_Z
void DEL_N(natural); //для DEL_Z
bool test(const integer, const integer); //для проверки
#include "../modules/DELZ_Z_Z.cpp" //user function
#include "../modules/NEW_Z_Z.cpp" //для user function
#include "../modules/DEL_Z.cpp" //для user function
#include "../modules/DELZ_N_N.cpp" //для user function
#include "../modules/NEW_N_N.cpp" //для NEW_Z
#include "../modules/DEL_N.cpp" //для DEL_Z
#include "test.cpp" //для проверки

int main()
{
	unsigned short n=1;
	char comment[256];
	fstream file("../tests/DELZ_Z_Z",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		integer z,_z,result,x; //Копируем z в _z
		file>>z.sign;
		_z.sign=z.sign;
		if (file.eof()) return 0;
		file>>z.module.count;
		_z.module.count=z.module.count;
		z=NEW_Z_Z(z);
		_z=NEW_Z_Z(_z);
		for(register unsigned short j=0;j<z.module.count;j++)
		{
			file>>z.module.digits[j];
			_z.module.digits[j]=z.module.digits[j];
		};
		file>>result.sign>>result.module.count;
		result=NEW_Z_Z(result);
		for(register unsigned short j=0;j<result.module.count;j++)
			file>>result.module.digits[j];
		file.ignore();
		file.getline(comment,255);
		file.sync();
		x=DELZ_Z_Z(z);//user function
		if (!test(z,_z)) //Проверка
		{
			cout<<"Ошибка! Данные, переданные в модуль, были изменены!";
			return 254;
		};
		if (!test(x/*user function*/,result))
		{
			cout<<"Ошибка в тесте "<<n<<":\n";
			for(register unsigned char i=0;comment[i];i++)
				cout<<comment[i];
			return n;
		};
		DEL_Z(z);
		DEL_Z(_z);
		DEL_Z(x);
		DEL_Z(result);
		n++;
	};
	return 0;
}
