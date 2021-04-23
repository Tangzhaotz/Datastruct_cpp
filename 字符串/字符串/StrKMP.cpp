#include<iostream>
#include<string>
using namespace std;

void get_next(const string& T, int* next)
{
	int j = 0;
	int i;
	next[0] = 0;
	for (i = 1; i < (int)T.length(); i++)
	{
		while (j > 0 && T[i] != T[j])   //不相等时，向前回溯
		{
			j = next[j - 1];
		}
		if (T[i] == T[j])  //相等的时候j++
		{
			j++;
		}
		next[i] = j;  //将next数组赋值
	}
}

int KMP(const string& s, const string& t)
{
	if (t.size() == 0)
	{
		return 0;
	}
	int *next = new int[t.size()];
	get_next(t, next);
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (j > 0 && s[i] != t[j])  //两个串出现不相等的元素
		{
			j = next[j - 1];  //此时j回溯到最长前缀对应的位置
		}
		if (s[i] == t[j])
		{
			j++;  //因为这里执行到最后一步匹配的话，j仍然需要加一，所以j的位置就是字串的最后一个元素的后一位，即j的大小就是子串的长度
		}
		if (j == t.size())  //匹配
		{
			return (i - t.size() + 1);  //计算子串匹配的位置
		}
	}
	return -1;

}

int main()
{
	string s, t;
	cout << "请输入主串：" << endl;
	cin >> s;
	cout << "请输入要匹配的字串：" << endl;
	cin >> t;
	int k = KMP(s,t);
	if (k != -1)
	{
		cout << "在主串的位置为：" << k << endl;
	}
	else
	{
		cout << "不匹配" << endl;
	}

	system("pause");

	return 0;
}