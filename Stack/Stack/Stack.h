#pragma once
#ifndef __Stack__
#define __Stack__
#define MAXSIZE 30
#include<iostream>
using namespace std;

class Stack
{
private:
	int top;  //ջ��
	int data[MAXSIZE];  //ջ��Ϊdata[0]

public:
	Stack();  //���캯��
	~Stack();  //��������
	bool push(int val);  //��ջ
	void traverse();  //����
	bool pop(int& val);  //��ջ
	bool is_empty();  //�ж��Ƿ�Ϊ��
	bool is_full();  //�ж��Ƿ�ջ��
};



Stack::Stack():top(-1)  //��ʼ����������ջ��ָ��ָ��-1��λ��
{

}

//��������
Stack::~Stack()
{

}

//��ջ����
bool Stack:: push(int val)
{
	//�����ж�ջ�Ƿ�����
	if (is_full())
	{
		return false;
	}
	//ջ����������£��Ƚ�ջ��ָ���ƶ�һλ���ٲ���Ԫ��
	top++;  //ջ��ָ���һ
	data[top] = val; //����Ԫ��
	return true;
}

//��ջ����
bool Stack::pop(int& val)
{
	//�����ж�ջ�Ƿ�Ϊ�գ�Ϊ����û��Ԫ�س�ջ
	if (is_empty())
	{
		return false;
	}
	//ջ��Ϊ��ʱ���Ƚ�Ԫ�ص������ٽ�ջ��ָ���һ
	val = data[top];
	top--;
	return true;
}

//����ջ
void Stack::traverse()
{
	int p = top;  //ָ��һ����־ָ��ջ��
	while (p != -1)  //��ջ��Ϊ��ʱ
	{
		cout << data[p] << " ";
		p--;//p�����ƶ�һ��λ��
	}
	cout << endl;
}

//�ж�ջ�Ƿ���
bool Stack::is_full()
{
	return MAXSIZE - 1 == top ? true : false;  //���ջ�е�Ԫ�ظ�����һΪջ��ָ���λ�ã����ж�ջ��
}

bool Stack::is_empty()
{
	return -1 == top ? true : false;  //��ջ��ָ��Ϊ-1ʱ����ʾջΪ��
}


#endif // !__Stack__

