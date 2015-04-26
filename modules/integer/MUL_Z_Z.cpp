// Copyright 2015 Vasilieva Maria, Rusyaev Sergey

#include "stdafx.h"
#include "struct.h"
#include <iostream>

//

//ћодуль MUL_Z_Z  (”множает целое число на (-1)):
//“ип integer представл€ет число в виде : sign(знак) и module(абсолютна€ величина)

int MUL_Z_Z (integer a) // функци€ модул€
{
	integer b; // инициализаци€ конечного результата
	b.module = a.module; // присваиваем результату абсолютную величину данного пользователем числа
	//ѕрисваиванием результату противоположный знак данного пользователем числа
	if (a.sign == 1)
	{
	b.sign = 0;
	}
	else
	b.sign = 1;
	return b; // возвращаем значение результата b
}


#ifndef MUL_Z_Z
#define MUL_Z_Z

#include "../../structs/struct.h"

ordinal MUL_Z_Z(integer a, integer b)
{
b.module = a.module;     // присваиваем результату абсолютную величину данного пользователем числа
	if (a.sign == 1) //ѕрисваиванием результату противоположный знак данного пользователем числа
	{
	b.sign = 0;
	}
	else
	b.sign = 1;
	return b; // возвращаем значение результата b
}
