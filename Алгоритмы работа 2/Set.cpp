#include "Set.h"
#include <iostream>

using namespace std;

void Set::input() {
	n = rand() % 16;
	int *B = new int[n];
	B = new int[n];
	for (int i = 0; i <= n; ++i)
		B[i] = rand() % 16;
	arrtolist(B);
	universum(spisok);
}

void Set::universum(list* B) {

	A = new int[N];
	for (int i = 0; i <= N; ++i)
		A[i] = 0;

	for (list* C = B->head; C; C = C->next)
		A[C->symbol] = 1;

}

void Set::arrtolist(int *c) {
	int i = 0;
	list* A = new list;
	A->head = A;
	do {							//заполн€ем список из массива
		A->symbol = c[i];
		i++;
		if (i != n) { //при последнем заходе мы таким образом не создадим лишний элемент
			A->next = new list;
			A->next->head = A->head;
			A = A->next;
		}
	} while (i != n);
	A->next = NULL;
	A = A->head;
}

void Set::show() {
	cout << "ћощьность множества";
}