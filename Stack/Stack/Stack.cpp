#include"Stack.h"
#include<iostream>

using namespace std;


int main()
{
	Stack s;  //����ջ����
	int val;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.traverse();  //����ջ
	s.pop(val);  //��ջ
	cout << "��ջ��ֵΪ��" << val << endl;


	system("pause");

	return 0;
}