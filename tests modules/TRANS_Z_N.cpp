#include <fstream>
#include <iostream>
#include "../struct.h"
natural TRANS_Z_N(const integer); //user function
natural ABS_Z_N(const integer); //для user function
natural COPY_N_N(const natural); //для ABS_Z_N
natural DELZ_N_N(const natural); //для ABS_Z_N
integer NEW_Z_Z(integer); //для ABS_Z_N
void DEL_Z(integer); //для ABS_Z_N
void DEL_N(natural); //для DEL_Z
natural NEW_N_N(natural); //для NEW_Z
bool test(const unsigned short, const unsigned short); //для проверки
#include "../modules/TRANS_Z_N.cpp" //user function
#include "../modules/ABS_Z_N.cpp" //для user function
#include "../modules/COPY_N_N.cpp" //для ABS_Z_N
#include "../modules/DELZ_N_N.cpp" //для ABS_Z_N
#include "../modules/NEW_Z_Z.cpp" //для ABS_Z_N
#include "../modules/DEL_Z.cpp" //для ABS_Z_N
#include "../modules/DEL_N.cpp" //для DEL_Z
#include "../modules/NEW_N_N.cpp" //для NEW_Z
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../tests/TRANS_Z_N",ios::in);
	unsigned short n=1;
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		integer z,_z; //Копируем z в _z
		natural x,result;
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
		file>>result.count;
		result=NEW_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		file.ignore();
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		x=TRANS_Z_N(z); //user function
		if (!test(z,_z)) //Проверка
		{
			cout<<"Ошибка! Данные, переданные в модуль, были изменены!";
			return 254;
		};
		if (x.digits==z.module.digits)
		{
			cout<<"Ошибка! Модуль вернул значение, которое было передано в него!";
			return 253;
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
		DEL_N(x);
		DEL_N(result);
		n++;
	};
	return 0;
};
