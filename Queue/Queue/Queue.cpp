/*
tangzhao
2021.4.14
*/

#include"Queue.h"
#include<iostream>
using namespace std;

int main()
{
	Queue s;
	int val;
	s.en_queue(1);
	s.en_queue(2);
	s.en_queue(3);
	s.en_queue(4);
	s.en_queue(5);
	s.traverse_queue();
	s.out_queue(val);
	cout << "出队的元素为：" << val << endl;


	system("pause");

	return 0;
}