#include <fstream>
#include <iostream>
#include "../struct.h"
natural MUL_ND_N(const natural, const unsigned short); //user function
natural ADD_NN_N(const natural, const natural); //для user function
bool NZER_N_B(const natural); //для COM_NN_D
unsigned short COM_NN_D(const natural, const natural); //для ADD_NN_N
natural DELZ_N_N(const natural); //для NZER_N_B
natural NEW_N_N(natural); //для DELZ_N_N
void DEL_N(natural); //для DELZ_N_N
natural MUL_Nk_N(const natural, const unsigned short); //для user function
natural COPY_N_N(const natural); //для ADD_NN_N
bool test(const natural, const natural); //для проверки
#include "../modules/MUL_ND_N.cpp" //user function
#include "../modules/ADD_NN_N.cpp" //для user function
#include "../modules/NZER_N_B.cpp" //для COM_NN_D
#include "../modules/DELZ_N_N.cpp" //для NZER_N_B
#include "../modules/NEW_N_N.cpp" //для DELZ_N_N
#include "../modules/DEL_N.cpp" //для DELZ_N_N
#include "../modules/MUL_Nk_N.cpp" //для user function
#include "../modules/COM_NN_D.cpp" //для ADD_NN_N
#include "../modules/COPY_N_N.cpp" //для ADD_NN_N
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../tests/MUL_ND_N",ios::in);
	unsigned short n=1;
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		natural x,_x,z,result; //Копируем x в _x
		unsigned short d;
		char comment[256];
		file>>x.count;
		if (file.eof()) return 0;
		x=NEW_N_N(x);
		for(register unsigned short j=0;j<x.count;j++)
			file>>x.digits[j];
		_x=COPY_N_N(x);
		file>>d>>result.count;
		result=NEW_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		file.ignore();
		file.getline(comment,255);
		file.sync(); //Чтение комментария к тесту
		z=MUL_ND_N(x,d);//user function
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
		DEL_N(x);
		DEL_N(_x);
		DEL_N(z);
		DEL_N(result);
		n++;
	};
	return 0;
};
