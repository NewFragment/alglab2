#pragma once

class Set {
private:
	struct list //множество
	{
		int symbol;
		list* next;
		list* head;
	};
	char S; //Тут будем различать какое у нас множество
	static int N; //Мощность универсума(для всех 16)
	int n; //Мощность множества
	
	int *A; //множество в виде массива

public:
	list *spisok; //множество в виде списка
	Set(char f);
	list* check(list*A, list*B, list*C, list*D);
	int* check_01(list* first, list* second, bool c);
	int* check_02(int* a, int b, int c);
	void input();
	void arrtolist(int *c, int b);
	void show();
	~Set();
};