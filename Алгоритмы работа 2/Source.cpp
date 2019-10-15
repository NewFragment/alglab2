#include <iostream>
#include <locale.h>
#include <time.h>
#include "Set.h"

using namespace std;

int main()
{
	Set A, B, C, D, E;

	clock_t start, end;
	float t;
	srand(time(nullptr)); //очистка псевдорандома, чтобы при каждой компиляции выдавало разный рандом

	setlocale(LC_ALL, "RUS");

	start = clock(); //старт счётчика времени

	end = clock(); //конец счётчика времени
	t = end - start; //рассчёт точного времени в секундах
	cout << "Затраченное время на вычисление: " << t / CLOCKS_PER_SEC << " секунд" << endl;

	
	system("pause");
	return 0;
}
