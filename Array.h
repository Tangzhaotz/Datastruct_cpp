#pragma once
class Arr
{
public:
	Arr(int len = 50);  //构造函数，初始化数组的长度
	~Arr();  //析构函数
	bool append_arr(int val);  //数组末尾追加元素
	bool insert_arr(int pos, int val);  //数组在pos位置插入一个元素
	bool delete_arr(int pos, int& val);  //删除数组中的某一个元素
	bool is_empty();  //判断数组是否为空
	bool is_full(); // 判断数组是否已满
	void sort_arr();  //数组从小到大排序
	void show_arr();  //输出数组中元素的个数
	void reverse_arr();//倒置数组
private:
	int* Bbase;  //存储的是数组第一个元素的地址
	int len;  //数组的长度
	int cnt = 0;  //当前数组有效元素的个数，即线性表的长度

};