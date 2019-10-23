#pragma once

class Set {
private:
	char S; //Тут будем различать какое у нас множество
	static int N; //Мощность универсума(для всех 16)
	int n; //Мощность множества
	int *A; //множество в виде массива
	int* univ; //отображение на универсум множества
public:
	Set(char f); //конструктор класса
	Set operator &= (const Set & B) const;
	Set operator |= (const Set & B) const;
	Set operator & (const Set & B) const;
	Set operator | (const Set & B) const;
	Set operator ~() const;
	Set(const Set&);
	void input();
	~Set(); //деструктор класса
};