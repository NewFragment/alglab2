#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "Set.h"

using namespace std;

int main()
{
	Set A, B, C, D, E;

	clock_t start, end;
	float t;
	srand(time(nullptr)); //������� �������������, ����� ��� ������ ���������� �������� ������ ������

	setlocale(LC_ALL, "RUS");

	start = clock(); //����� �������� �������

	end = clock(); //����� �������� �������
	t = end - start; //������� ������� ������� � ��������
	cout << "����������� ����� �� ����������: " << t / CLOCKS_PER_SEC << " ������" << endl;

	
	system("pause");
	return 0;
}
