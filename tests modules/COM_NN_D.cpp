#include <fstream>
#include <iostream>
#include "../struct.h"
natural DELZ_N_N(const natural, const natural); //для NZER_N_B
void DEL_N(natural); //для DELZ_N_N
natural NEW_N_N(natural); //для DELZ_N_N
unsigned short COM_NN_D(const natural, const natural); //user function
bool test(const unsigned short, const unsigned short); //для проверки
bool NZER_N_B(const natural); //для user function
natural COPY_N_N(const natural); //для проверки
#include "../modules/DELZ_N_N.cpp" //для NZER_N_B
#include "../modules/DEL_N.cpp" //для DELZ_N_N
#include "../modules/NEW_N_N.cpp" //для DELZ_N_N
#include "../modules/COM_NN_D.cpp" //user function
#include "../modules/NZER_N_B.cpp" //для user function
#include "../modules/COPY_N_N.cpp" //для проверки
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../tests/COM_NN_D",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	unsigned short n=1;
	while (!file.eof())
	{
		natural x,y,_x,_y; //Копируем x в _x, y в _y
		unsigned short z,result;
		char comment[256];
		file>>x.count;
		if (file.eof()) return 0;
		x=NEW_N_N(x);
		for(register unsigned short i=0;i<x.count;i++)
			file>>x.digits[i];
		_x=COPY_N_N(x);
		file>>y.count;
		y=NEW_N_N(y);
		for(register unsigned short i=0;i<y.count;i++)
			file>>y.digits[i];
		_y=COPY_N_N(y);
		file>>result;
		file.ignore(); 
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		z=COM_NN_D(x,y); //user function
		if (!test(x,_x) || !test(y,_y)) //Проверка
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
		DEL_N(y);
		DEL_N(_x);
		DEL_N(_y);
		n++;
	};
	return 0;
};
