#pragma once


using namespace std;

class Set {

	struct list //множество
	{
		int symbol;
		list* next;
		list* head;
	};

private:

	static int N; //Мощьность универсума(16)
	int n; //Мощность множества
	list *spisok; //множество в виде списка
	int *A; //универсум множества

public:
	void input();
	void universum(list* B);
	void arrtolist(int *c);
	void show();


};