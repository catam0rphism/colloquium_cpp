#include <fstream>
#include <iostream>
#include "../struct.h"
natural MUL_NN_N(const natural, const natural); //user function
natural MUL_ND_N(const natural, const unsigned short); //для user function
natural ADD_NN_N(const natural, const natural); //для MUL_ND_N
natural MUL_Nk_N(const natural, const unsigned short); //для MUL_ND_N
unsigned short COM_NN_D(const natural, const natural); //для ADD_NN_N
bool NZER_N_B(const natural); //для COM_NN_D
natural DELZ_N_N(const natural); //для NZER_N_B
void DEL_N(natural); //для DELZ_N_N
natural NEW_N_N(natural); //для DELZ_N_N
bool test(const natural, const natural); //для проверки
natural COPY_N_N(const natural); //для ADD_NN_N
#include "../modules/MUL_NN_N.cpp" //user function
#include "../modules/MUL_ND_N.cpp" //для user function
#include "../modules/ADD_NN_N.cpp" //для MUL_ND_N
#include "../modules/MUL_Nk_N.cpp" //для MUL_ND_N
#include "../modules/COM_NN_D.cpp" //для ADD_NN_N
#include "../modules/NZER_N_B.cpp" //для COM_NN_D
#include "../modules/DELZ_N_N.cpp" //для NZER_N_B
#include "../modules/DEL_N.cpp" //для DELZ_N_N
#include "../modules/NEW_N_N.cpp" //для DELZ_N_N
#include "../modules/COPY_N_N.cpp" //для ADD_NN_N
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	unsigned short n=1;
	fstream file("../tests/MUL_NN_N",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		natural x,y,_x,_y,z,result; //Копируем x в _x, y в _y
		char comment[256];
		file>>x.count;
		if (file.eof()) return 0;
		x=NEW_N_N(x);
		for(register unsigned short j=0;j<x.count;j++)
			file>>x.digits[j];
		_x=COPY_N_N(x);
		file>>y.count;
		y=NEW_N_N(y);
		for(register unsigned short j=0;j<y.count;j++)
			file>>y.digits[j];
		_y=COPY_N_N(y);
		file>>result.count;
		result=NEW_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		file.ignore(); 
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		z=MUL_NN_N(x,y);//user function
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
		DEL_N(x);
		DEL_N(_x);
		DEL_N(y);
		DEL_N(_y);
		DEL_N(z);
		DEL_N(result);
		n++;
	};
	return 0;
};
