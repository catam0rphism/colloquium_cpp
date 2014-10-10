#include <fstream>
#include "../struct.h"
void DELN_N(const natural); //для проверки
bool test(const natural); //для проверки
natural NEWN_N_N(natural); //user function
#include "../Модули/NEWN_N_N.cpp" //user function
#include "test.cpp" //для проверки
#include "../Модули/DELN_N.cpp" //для проверки
using namespace std;

int main()
{
	fstream file("../Тесты/NEWN_N_N",ios::in);
	unsigned short n;
	if (!file) return 254; //Проверка на существование тестов
	file>>n;
	for(register unsigned short i=1;i<=n;i++)
	{
		natural x;
		file>>x.count;
		NEWN_N_N(x); //user function
		//if (!test(x)) return i;
		DELN_N(x);
	};
	return 0;
}
