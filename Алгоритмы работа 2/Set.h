#pragma once


using namespace std;

class Set {

	struct list //���������
	{
		int symbol;
		list* next;
		list* head;
	};

private:

	static int N; //��������� ����������(16)
	int n; //�������� ���������
	list *spisok; //��������� � ���� ������
	int *A; //��������� ���������

public:
	void input();
	void universum(list* B);
	void arrtolist(int *c);
	void show();


};