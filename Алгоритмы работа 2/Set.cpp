#include "Set.h"
#include <iostream>

Set::Set(): //Конструктор для E
	Arr(NULL), Name('E')
{ 

}

Set::Set(char name) : //основной Конструктор
	Name(name), Arr(NULL)
{
		Arr = NULL;
		initialize();
		printToConsole();
}

Set::Set(const Set &B): //Конструктор копии
	Arr(NULL), n(B.n), Name('E')
{
	UniversumDisplay = new int[N];
	for (int i = 0; i < N; i++)
		UniversumDisplay[i] = B.UniversumDisplay[i];
	//cout << "Созданна копия " << B.Name << endl;
}

Set Set::operator &= (const Set &B) const {
	for (int i = 0; i < N; i++)
		if (UniversumDisplay[i] == 1 && B.UniversumDisplay[i] == 1)
			UniversumDisplay[i] = 1;
		else
			UniversumDisplay[i] = 0;
	return *this;
}

Set Set::operator & (const Set &B) const {
	Set C(*this);
	//cout << "Применен оператор & для " << this->Name << " & " << B.Name << " = E" << endl;
	return (C &= B);
}

Set Set::operator |= (const Set &B) const {
	for (int i = 0; i < N; i++)
		if(B.UniversumDisplay[i] == 1)
		UniversumDisplay[i] = 1;
	return *this;
}

Set Set::operator | (const Set &B) const {
	Set C(*this);
	//cout << "Применен оператор | для " << this->Name << " | " << B.Name << " = E" << endl;
	return (C |= B);
}

Set Set::operator ~() const {
	for (int i = 0; i < N; i++)
		if (this->UniversumDisplay[i] == 0) this->UniversumDisplay[i] = 1;
		else this->UniversumDisplay[i] = 0;
	//cout << "Применен оператор ~ для " << this->Name << endl;
	return *this;
}

void Set::initialize() {
	n = rand() % 16;
		Arr = new int[n];
		for (int i = 0; i <= n; ++i)
			Arr[i] = rand() % 16;
			UniversumDisplay = new int[N];
		for (int i = 0; i < N; i++)
			UniversumDisplay[i] = 0;
		for (int i = 0; i < n; i++)
			UniversumDisplay[Arr[i]] = 1;
}

void Set::printToConsole() const {
	if (Name != 'E') {
		cout << Name << ": [";
		for (int i = 0; i < n; ++i)
			if (Name == 'E')
				cout << hex << i << " ";
			else
				cout << hex << Arr[i] << " ";
		cout << "] ";
		for (int i = 0; i < N; ++i)
			cout << UniversumDisplay[i];
		cout << endl;
	}
	else {
		cout << Name << ": [";
		for (int i = 0; i < N; ++i)
			if (UniversumDisplay[i] == 1)
				cout << hex << i << " ";
		cout << "] ";
		for (int i = 0; i < N; ++i)
			cout << UniversumDisplay[i];
			cout << endl;
	}
}

Set::~Set() { //Деструктор класса

}