//���ݽṹһ�����Ա�
//tangzhao
//2021.4.11 21:00

//1�����鳤�������Ա��ȵ���������ĳ����Ǵ�����Ա�Ĵ洢�ռ�ĳ��ȣ��洢����������һ���ǲ����
//���Ա�ĳ��������Ա�������Ԫ�صĸ������������Ա�Ĳ����ɾ����������Ǳ仯��

#include "Array.h"
#include<iostream>
using namespace std;

Arr::Arr(int len) :len(len), Bbase(new int[len])  //��ʼ�����飬�ڶ�����������������С����һ���ռ�
{

}

Arr::~Arr()
{
	delete[] Bbase;  //ɾ�����飬��������
}

//�ж������Ƿ�Ϊ��
bool Arr::is_empty()
{
	return cnt == 0 ? true : false;
}

//�������
void Arr::show_arr()
{
	if (is_empty())  //���ж������Ƿ�Ϊ��
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << Bbase[i] << " ";
		}
		cout << endl;
	}
}

//�ж������Ƿ�Ϊ��
bool Arr::is_full()
{
	return cnt == len ? true : false;
}

//׷��һ��Ԫ��
bool Arr::append_arr(int val)
{
	if (is_full())  //���ж������Ƿ�����
	{
		cout << "��������" << endl;
		return false;
	}
	else
	{
		Bbase[cnt] = val;
		cnt++;

		//����
		//Bbase[cnt++] = val;
		return true;
	}
}

//��ĳһ��λ�ò���Ԫ��
bool Arr::insert_arr(int pos,int val)  //����pos�ķ�Χ��1��cnt
{
	if (pos < 1 || pos > cnt + 1)
	{
		return false;
	}
	for (int i = cnt - 1; i >= pos - 1; i--)  //��������Ԫ���±��pos-1��cnt-1��Ԫ������������һ��λ��
	{
		Bbase[i + 1] = Bbase[i];
	}
	Bbase[pos - 1] = val;
	cnt++;
	return true;  //����ɹ�
}

//ɾ��Ԫ��
bool Arr::delete_arr(int pos,int &val)
{
	if (is_empty())
	{
		return false;
	}
	if (pos < 1 || pos >cnt)  //ע������Ͳ���ʱ��һ��������Ҫдcnt+1����Ϊɾ����������������Ԫ�صĸ���������Ҫ�ж���һ��λ��
	{
		return false;
	}

	val = Bbase[pos - 1];  //��ȡҪɾ����Ԫ�أ���Щ�㷨Ҫ�󷵻�ɾ����Ԫ��

	for (int i = pos; i < cnt; i++)
	{
		Bbase[i - 1] = Bbase[i];
	}
	cnt--;
	return true;

}

//��������
void Arr::reverse_arr()
{
	int i = 0;
	int j = cnt - 1;
	int t;
	while (i < j)
	{
		t = Bbase[i];
		Bbase[i] = Bbase[j];
		Bbase[j] = t;
		i++;
		j--;
	}
}


//����Ԫ�ش�С��������
void Arr::sort_arr()
{
	int i,j,t;
	for (int i = 0; i < cnt; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (Bbase[i] > Bbase[j])
			{
				t = Bbase[i];
				Bbase[i] = Bbase[j];
				Bbase[j] = t;
			}
		}
	}
}


int main()
{
	Arr arr;  //��������
	arr.append_arr(5);
	arr.append_arr(6);
	arr.append_arr(15);
	arr.append_arr(1);
	arr.append_arr(3);
	arr.append_arr(20);

	arr.show_arr();//��ʾ����
	//arr.reverse_arr();  //��������
	//arr.show_arr();
	/*arr.sort_arr();
	arr.show_arr();*/

	//����Ԫ��
	/*arr.insert_arr(3, 10);
	arr.show_arr();*/

	//ɾ��Ԫ��
	int val;
	arr.delete_arr(3, val);
	cout << "ɾ����Ԫ��Ϊ��" << val << endl;
	arr.show_arr();

	system("pause");

	return 0;
}