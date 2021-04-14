#pragma once
#ifndef __Stack__
#define __Stack__
#define MAXSIZE 30
#include<iostream>
using namespace std;

class Stack
{
private:
	int top;  //栈顶
	int data[MAXSIZE];  //栈底为data[0]

public:
	Stack();  //构造函数
	~Stack();  //析构函数
	bool push(int val);  //进栈
	void traverse();  //遍历
	bool pop(int& val);  //出栈
	bool is_empty();  //判断是否为空
	bool is_full();  //判断是否栈满
};



Stack::Stack():top(-1)  //初始化参数，将栈顶指针指向-1的位置
{

}

//析构函数
Stack::~Stack()
{

}

//进栈操作
bool Stack:: push(int val)
{
	//首先判断栈是否已满
	if (is_full())
	{
		return false;
	}
	//栈不满的情况下，先将栈顶指针移动一位，再插入元素
	top++;  //栈顶指针加一
	data[top] = val; //插入元素
	return true;
}

//出栈操作
bool Stack::pop(int& val)
{
	//首先判断栈是否为空，为空则没有元素出栈
	if (is_empty())
	{
		return false;
	}
	//栈不为空时，先将元素弹出，再将栈顶指针减一
	val = data[top];
	top--;
	return true;
}

//遍历栈
void Stack::traverse()
{
	int p = top;  //指定一个标志指向栈顶
	while (p != -1)  //当栈不为空时
	{
		cout << data[p] << " ";
		p--;//p向下移动一个位置
	}
	cout << endl;
}

//判断栈是否满
bool Stack::is_full()
{
	return MAXSIZE - 1 == top ? true : false;  //如果栈中的元素个数减一为栈顶指针的位置，则判断栈满
}

bool Stack::is_empty()
{
	return -1 == top ? true : false;  //当栈顶指针为-1时，表示栈为空
}


#endif // !__Stack__

