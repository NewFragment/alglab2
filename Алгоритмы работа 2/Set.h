#pragma once

using namespace std;

class Set {
private:
	char Name; //Тут будем различать какое у нас множество
	static int N; //Мощность универсума
	int n; //Мощность множества(размер массива)
	int* Arr; //Наше множество
	int* UniversumDisplay; //Отображение на универсум множества
public:
	Set();//Конструктор класса для E
	Set(char); //Дефолтный Конструктор класса
	Set(const Set &); //Конструктор копии
	Set operator &= (const Set &) const; //Перегрузка оператора побитовое И
	Set operator & (const Set &B) const; //Дополнение к перегрузке
	Set operator |= (const Set &) const;  //Перегрузка оператора побитовое ИЛИ
	Set operator | (const Set &B) const; //Дополнение к перегрузке
	Set operator ~() const; //Перегрузка оператора отрицания
	void printToConsole() const; //Вывод на экран
	void initialize(); //Инициализация случайных значений
	~Set(); //деструктор класса
};