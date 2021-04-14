#include"Stack.h"
#include<iostream>

using namespace std;


int main()
{
	Stack s;  //创建栈对象
	int val;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.traverse();  //遍历栈
	s.pop(val);  //出栈
	cout << "出栈的值为：" << val << endl;


	system("pause");

	return 0;
}