﻿#include <iostream>
#include <locale.h>
#include <time.h>
#include "Set.h"

using namespace std;

int main()
{
	srand(time(nullptr)); //очистка псевдорандома, чтобы при каждой компиляции выдавало разный рандом
	setlocale(LC_ALL, "RUS");
	Set A{ 'A' }, B{ 'B' }, C{ 'C' }, D{ 'D' }, E{ 'E' };
	clock_t start, end;
	float t;
	start = clock(); //старт счётчика времени

	E.check(A.spisok, B.spisok, C.spisok, D.spisok);
	end = clock(); //конец счётчика времени
	t = end - start; //рассчёт точного времени в секундах
	cout << "Затраченное время на вычисление: " << t / CLOCKS_PER_SEC << " секунд" << endl;

	system("pause");
	return 0;
}
