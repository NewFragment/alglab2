#include <iostream>
#include <locale.h>
#include <time.h>
#include "Set.h"

int Set::N = 16;

int main()
{
	srand(time(nullptr)); //очистка псевдорандома, чтобы при каждой компиляции выдавало разный рандом
	setlocale(LC_ALL, "RUS");

	Set A{ 'A' }, B{ 'B' }, C{ 'C' }, D{ 'D' }, E;
	clock_t start, end;
	float t;
	//cout << "E = (A|C) & (~(B & D))"<< endl;
	start = clock(); //старт счётчика времени
	
	//for(int i = 0; i < 10000; ++i)
	E = (A | C) & (~(B & D));
	E.printToConsole();

	end = clock(); //конец счётчика времени
	t = end - start; //рассчёт точного времени в секундах
	cout << "Затраченное время на вычисление: " << t / CLOCKS_PER_SEC << " секунд" << endl;

	system("pause");
	return 0;
}