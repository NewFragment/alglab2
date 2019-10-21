#include "Set.h"
#include <iostream>

using namespace std;

Set::Set(char f) {
	S = f;
	if (S != 'E') {
		A = NULL;
		spisok = NULL;
		input();
	}
	else {
		A = NULL;
		spisok = NULL;
	}
}

Set::list * Set::check(Set::list * A, Set::list * B, Set::list * C, Set::list * D)
{
	if (!A && !C) return NULL;
	int* spisok = NULL; //массив, который потом станет E
	int count = 0; //размер массива

	int* u1 = check_01(A, C, false); //отображение на универсум A ИЛИ C
	int* u2 = check_01(B, D, true); //отображение на универсум B И D

	for (int i = 0; i < 16; i++) u1[i] = u1[i] * u2[i]; //Применяем побитовое умножение чтобы получить результат
	for (int i = 0; i < 16; i++) //записываем результат в массив
	{
		if (u1[i] == 1) //берём наш универсум и если мы наткнулись на единицу
		{
			spisok = check_02(spisok, count, i); //то запихиваем в массив порядковый номер
			count++; //увеличиваем размер массива
		}
	}
	if (spisok)
		 arrtolist(spisok, count);   //сразу возвращаем список
	else
		return NULL;
}

int* Set::check_01(Set::list* first, Set::list* second, bool c)
{
	int* u = new int[16];

	for (int i = 0; i < 16; ++i) //создаём нулевой массив
		u[i] = 0;

	if (c) { //если на вход принимаются B и D и они оба не пустые, то заполняем универсум (B && D)
		if (first)
			for (list*a = first->head; a; a = a->next)
				if (second)
					for (list*b = second->head; b; b = b->next) {
						if (a->symbol == b->symbol) {
							u[a->symbol] = 1;
							break;
						}
					}
				else break;
		for (int i = 0; i < 16; ++i) //отображение инвертируем по условию (~)
			u[i] == 1 ? u[i] = 0 : u[i] = 1;
		return u;
	}
	if (first)
		for (list*a = first->head; a; a = a->next)	 //заполняем отображение по первому множеству
			u[a->symbol] = 1;

	if (second)
		for (list*a = second->head; a; a = a->next)	//и по второму туда же
			u[a->symbol] = 1;

	return u;
}

int* Set::check_02(int* a, int b, int c) {

	if (!a) {	//при первом заходе создаём массив и записываем цифру
		a = new int;
		a[b] = c; //записываем цифру в массив

	}
	else {		//при последующих увеличиваем память на 1 ячейку и записываем цифру
		a = (int*)realloc(a, (c + 1) * sizeof(int));
		a[b] = c; //записываем цифру в массив
	}
	return a;
}

void Set::input() {
	n = rand() % 16;
	A = new int[n];
	for (int i = 0; i <= n; ++i)
		A[i] = rand() % 16;
	arrtolist(A, n);
}



void Set::arrtolist(int *c, int b) {
	int i = 0;
	spisok = new list;
	spisok->head = spisok;
	do {							//хуячим список из массива
		spisok->symbol = c[i];
		i++;
		if (i != b) { //при последнем заходе мы таким образом не создадим лишний элемент
			spisok->next = new list;
			spisok->next->head = spisok->head;
			spisok = spisok->next;
		}
	} while (i != b);
	spisok->next = NULL;
	spisok = spisok->head;
	show();
}



void Set::show() {
		if (spisok)
		{
			
			cout << "Множество '" << S << "': { ";
			for (list *p = spisok->head; p; p = p->next)
			{
				if (p->next)
					cout << hex << p->symbol << "; ";
				else cout << hex << p->symbol << " ";
			}
			cout << "}" << endl;
		}
		else cout << "Множество '" << S << "' - пустое" << endl;
}

Set::~Set() {
	cout << "Память очищенна!";
}