#include <fstream>
#include <iostream>
#include "../struct.h"
natural SUB_NDN_N(const natural, const unsigned short, const natural); //user function
natural MUL_ND_N(const natural, const unsigned short); //для user function
natural SUB_NN_N(const natural, const natural); //для user function
natural ADD_NN_N(const natural, const natural); //для MUL_ND_N
natural MUL_Nk_N(const natural, const unsigned short); //для MUL_ND_N
unsigned short COM_NN_D(const natural, const natural); //для ADD_NN_N
bool NZER_N_B(const natural); //для COM_NN_D
natural DELZ_N_N(const natural); //для NZER_N_B
void DELN_N(natural); //для DELZ_N_N
natural NEWN_N_N(const natural); //для DELZ_N_N
bool test(const natural, const natural); //для проверки
#include "../modules/SUB_NDN_N.cpp" //user function
#include "../modules/MUL_ND_N.cpp" //для user function
#include "../modules/SUB_NN_N.cpp" //для user function
#include "../modules/ADD_NN_N.cpp" //для MUL_ND_N
#include "../modules/MUL_Nk_N.cpp" //для MUL_ND_N
#include "../modules/COM_NN_D.cpp" //для ADD_NN_N
#include "../modules/NZER_N_B.cpp" //для COM_NN_D
#include "../modules/DELZ_N_N.cpp" //для NZER_N_B
#include "../modules/DELN_N.cpp" //для DELZ_N_N
#include "../modules/NEWN_N_N.cpp" //для DELZ_N_N
#include "test.cpp" //для проверки
using namespace std;

int main()
{
	unsigned short n=1;
	fstream file("../tests/SUB_NDN_N",ios::in);
	if (!file)//Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	}
	while (!file.eof())
	{
		natural x,y,_x,_y,z,result; //Копируем x в _x, z в _z
		unsigned short d;
		char comment[256];
		file>>x.count;
		if (file.eof()) return 0;
		_x.count=x.count;
		x=NEWN_N_N(x);
		_x=NEWN_N_N(_x);
		for(register unsigned short i=0;i<x.count;i++)
		{
			file>>x.digits[i];
			_x.digits[i]=x.digits[i];
		};
		file>>d;
		file>>y.count;
		_y.count=y.count;
		y=NEWN_N_N(y);
		_y=NEWN_N_N(_y);
		for(register unsigned short i=0;i<y.count;i++)
		{
			file>>y.digits[i];
			_y.digits[i]=y.digits[i];
		};
		file>>result.count;
		result=NEWN_N_N(result);
		for(register unsigned short i=0;i<result.count;i++)
			file>>result.digits[i];
		file.ignore();
		file.getline(comment,256);
		file.sync();//Чтение комментария к тесту
		z=SUB_NDN_N(x,d,y);
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
