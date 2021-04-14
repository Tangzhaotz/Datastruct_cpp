/*
tangzhao
2021.4.14
*/

#pragma once
#ifndef __Queue__

#define __Queue__
#include<iostream>
using namespace std;

class Queue
{
public:
	Queue(int len = 6);
	~Queue();

	bool en_queue(int val);  //入队
	bool out_queue(int& val);  //出队
	void traverse_queue();//遍历
	bool is_full();  //判断是否为满
	bool is_empty();  //判断是否为空

private:
	int len;  //数组长度
	int* pbase;  //数组位置
	int front;  //队头
	int rear;  //队尾
};



Queue::Queue(int len):len(len),pbase(new int[len]),front(0),rear(0)
{

}

Queue::~Queue()
{

}

//插入元素
bool Queue::en_queue(int val)
{
	if (is_full())  //队列已满
	{
		return false;
	}
	pbase[rear] = val;  //元素插入队尾
	rear = (rear + 1) % len;  //队尾指针移动
	return true;
}

void Queue::traverse_queue()
{
	int i = front;
	while (i != rear)
	{
		cout << pbase[i] << " ";
		i = (i + 1) % len;
	}
	cout << endl;
}

//判断队列是否已满
bool Queue::is_full()
{
	return (rear + 1) % len == front ? true : false;  //判断循环队列满的条件
}

//判断队列的是否为空
bool Queue::is_empty()
{
	return front == rear ? true : false;
}

//出队
bool Queue::out_queue(int& val)
{
	if (is_empty())
	{
		return false;
	}
	val = pbase[front];
	front = (front + 1) % len;
	return true;
}

#endif // !__Queue__
