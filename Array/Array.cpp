//数据结构一：线性表
//tangzhao
//2021.4.11 21:00

//1、数组长度与线性表长度的区别：数组的长度是存放线性表的存储空间的长度，存储分配后这个量一般是不变的
//线性表的长度是线性表中数据元素的个数，随着线性表的插入和删除，这个量是变化的

#include "Array.h"
#include<iostream>
using namespace std;

Arr::Arr(int len) :len(len), Bbase(new int[len])  //初始化数组，在堆区根据输入的数组大小申请一个空间
{

}

Arr::~Arr()
{
	delete[] Bbase;  //删除数组，析构函数
}

//判断数组是否为空
bool Arr::is_empty()
{
	return cnt == 0 ? true : false;
}

//输出数组
void Arr::show_arr()
{
	if (is_empty())  //先判断数组是否为空
	{
		cout << "数组为空" << endl;
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

//判断数组是否为满
bool Arr::is_full()
{
	return cnt == len ? true : false;
}

//追加一个元素
bool Arr::append_arr(int val)
{
	if (is_full())  //先判断数组是否已满
	{
		cout << "数组已满" << endl;
		return false;
	}
	else
	{
		Bbase[cnt] = val;
		cnt++;

		//或者
		//Bbase[cnt++] = val;
		return true;
	}
}

//在某一个位置插入元素
bool Arr::insert_arr(int pos,int val)  //这里pos的范围是1到cnt
{
	if (pos < 1 || pos > cnt + 1)
	{
		return false;
	}
	for (int i = cnt - 1; i >= pos - 1; i--)  //把数组中元素下标从pos-1到cnt-1的元素依次往后移一个位置
	{
		Bbase[i + 1] = Bbase[i];
	}
	Bbase[pos - 1] = val;
	cnt++;
	return true;  //插入成功
}

//删除元素
bool Arr::delete_arr(int pos,int &val)
{
	if (is_empty())
	{
		return false;
	}
	if (pos < 1 || pos >cnt)  //注意这里和插入时不一样，不需要写cnt+1，因为删除不会增加数组中元素的个数，不需要判断下一个位置
	{
		return false;
	}

	val = Bbase[pos - 1];  //获取要删除的元素，有些算法要求返回删除的元素

	for (int i = pos; i < cnt; i++)
	{
		Bbase[i - 1] = Bbase[i];
	}
	cnt--;
	return true;

}

//倒置数组
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


//数组元素从小到大排序
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
	Arr arr;  //创建对象
	arr.append_arr(5);
	arr.append_arr(6);
	arr.append_arr(15);
	arr.append_arr(1);
	arr.append_arr(3);
	arr.append_arr(20);

	arr.show_arr();//显示数组
	//arr.reverse_arr();  //逆置数组
	//arr.show_arr();
	/*arr.sort_arr();
	arr.show_arr();*/

	//插入元素
	/*arr.insert_arr(3, 10);
	arr.show_arr();*/

	//删除元素
	int val;
	arr.delete_arr(3, val);
	cout << "删除的元素为：" << val << endl;
	arr.show_arr();

	system("pause");

	return 0;
}