#include "Set.h"
#include <iostream>

using namespace std;

Set::Set(char f) : //Конструктор класса
	S(f) 
{
	if (S != 'E') {
		A = NULL;
		input();
	}
	else {
		A = NULL;
		univ = new int[N];
		for (int i = 0; i < N; i++)
			univ[i] = 0;
	}
}

Set::Set(const Set&set) :
	S(set.S), n(set.n), A(set.A), univ(set.univ)
{
	
}


Set Set::operator &= (const Set & B) const {
	Set C(*this);
	int b = 0;
	for(int i = 0; i < C.n; i++)
		for(int j = 0; j < B.n; j++)
			if (C.A[i] == B.A[j]) {
				univ[C.A[i]] = 1;
			}
	return *this;
}

Set Set::operator & (const Set & B) const {
	Set C(*this);
	return(C &= B);
}

Set Set::operator |= (const Set & B) const {
	Set C(*this);
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < B.n; j++) {
			C.univ[A[i]] = 1;
			C.univ[B.A[j]] = 1;
		}
	return *this;
}
Set Set::operator | (const Set & B) const {
	Set C(*this);
	return(C |= B);
}
Set Set::operator ~() const {
	Set C('E');
	for (int i = 0; i < N; i++)
		if (univ[i] == 0) univ[i] = 1;
		else univ[i] = 0;
	return (*this);
}

void Set::input() {
	n = rand() % 16;
	A = new int[n];
	for (int i = 0; i <= n; ++i)
		A[i] = rand() % 16;

	univ = new int[N];
	for (int i = 0; i < N; i++)
		univ[i] = 0;
}

Set::~Set() { //Деструктор класса
	
}