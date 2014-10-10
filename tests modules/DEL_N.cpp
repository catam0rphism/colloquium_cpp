#include <fstream>
using namespace std;
#include "../struct.h"
natural NEWN_N_N(natural); //для проверки
void DELN_N(natural); //user function
bool test(const natural); //для проверки
#include "../Модули/DELN_N.cpp" //user function
#include "test.cpp" //для проверки
#include "../Модули/NEWN_N_N.cpp" //для проверки


int main()
{
	fstream file("../Тесты/DELN_N",ios::in);
	unsigned short n;
	if (!file) return 254; //Проверка на существование тестов
	file>>n;
	for(register unsigned short i=1;i<=n;i++)
	{
		natural x;
		file>>x.count;
		x=NEWN_N_N(x);
		for(register unsigned short j=0;j<x.count;j++)
			file>>x.digits[j];
		DELN_N(x); //user function
		//if (test(x)) return i;
	};
	file.close();
	return 0;
}
