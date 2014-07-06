#include <fstream>
#include <iostream>
#include "../struct.h"
natural ADD_NN_N(const natural, const natural); //user function
unsigned short COM_NN_D(const natural, const natural); //для user function
bool NZER_N_B(const natural); //для COM_NN_D
natural DELZ_N_N(const natural); //для NZER_N_B
natural NEWN_N_N(natural); //для DELZ_N_N
void DELN_N(natural); //для DELZ_N_N
bool test(const natural, const natural); //для проверки
#include "../modules/ADD_NN_N.cpp" //user function
#include "../modules/COM_NN_D.cpp" //для user function
#include "../modules/NZER_N_B.cpp" //для COM_NN_D
#include "../modules/DELZ_N_N.cpp" //для NZER_N_B
#include "../modules/NEWN_N_N.cpp" //для DELZ_N_N
#include "../modules/DELN_N.cpp" //для DELZ_N_N
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../tests/ADD_NN_N",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	unsigned short n=1;
	while (!file.eof())
	{
		natural x,y,_x,_y,z,result; //Копируем x в _x, y в _y
		char comment[256];
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
		file>>y.count;
		_y.count=y.count;
		y=NEWN_N_N(y);
		_y=NEWN_N_N(_y);
		for(register unsigned short j=0;j<y.count;j++)
		{
			file>>y.digits[j];
			_y.digits[j]=y.digits[j];
		};
		file>>result.count;
		result=NEWN_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		file.ignore(); 
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		z=ADD_NN_N(x,y);//user function
		if (!test(x,_x) || !test(y,_y)) //Проверка на сохранность данных
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
		DELN_N(y);
		DELN_N(_y);
		DELN_N(z);
		DELN_N(result);
		n++;
	};
	return 0;
};
