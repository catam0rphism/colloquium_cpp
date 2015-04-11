#include <fstream>
#include <iostream>
#include "../struct.h"
unsigned short SGN_Z_D(const integer); //user function
integer DELZ_Z_Z(const integer); //для user function
natural DELZ_N_N(const natural); //для DELZ_Z_Z
integer NEW_Z_Z(integer); //для DELZ_Z_Z
void DEL_Z(integer); //для DELZ_Z_Z
natural NEW_N_N(natural); //для NEW_Z
void DEL_N(natural); //для DEL_Z
bool test(const unsigned short, const unsigned short); //для проверки
#include "../modules/SGN_Z_D.cpp" //user function
#include "../modules/DELZ_Z_Z.cpp" //для user function
#include "../modules/NEW_Z_Z.cpp" //для DELZ_Z_Z
#include "../modules/DEL_Z.cpp" //для DELZ_Z_Z
#include "../modules/DELZ_N_N.cpp" //для DELZ_Z_Z
#include "../modules/DEL_N.cpp" //для DEL_Z
#include "../modules/NEW_N_N.cpp" //для NEW_Z
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../tests/SGN_Z_D",ios::in);
	unsigned short n=1;
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		integer z,_z; //Копируем z в _z
		unsigned short x,result;
		char comment[256];
		file>>z.sign;
		_z.sign=z.sign;
		if (file.eof()) return 0;
		file>>z.module.count;
		_z.module.count=z.module.count;
		z=NEW_Z_Z(z);
		_z=NEW_Z_Z(_z);
		for(register unsigned short i=0;i<z.module.count;i++)
		{
			file>>z.module.digits[i];
			_z.module.digits[i]=z.module.digits[i];
		}
		file>>result;
		file.ignore();
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		x=SGN_Z_D(z); //user function
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
		n++;
	};
	return 0;
};

