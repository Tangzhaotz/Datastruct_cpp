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

	bool en_queue(int val);  //���
	bool out_queue(int& val);  //����
	void traverse_queue();//����
	bool is_full();  //�ж��Ƿ�Ϊ��
	bool is_empty();  //�ж��Ƿ�Ϊ��

private:
	int len;  //���鳤��
	int* pbase;  //����λ��
	int front;  //��ͷ
	int rear;  //��β
};



Queue::Queue(int len):len(len),pbase(new int[len]),front(0),rear(0)
{

}

Queue::~Queue()
{

}

//����Ԫ��
bool Queue::en_queue(int val)
{
	if (is_full())  //��������
	{
		return false;
	}
	pbase[rear] = val;  //Ԫ�ز����β
	rear = (rear + 1) % len;  //��βָ���ƶ�
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

//�ж϶����Ƿ�����
bool Queue::is_full()
{
	return (rear + 1) % len == front ? true : false;  //�ж�ѭ��������������
}

//�ж϶��е��Ƿ�Ϊ��
bool Queue::is_empty()
{
	return front == rear ? true : false;
}

//����
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
