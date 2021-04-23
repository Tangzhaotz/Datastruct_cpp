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
		while (j > 0 && T[i] != T[j])   //�����ʱ����ǰ����
		{
			j = next[j - 1];
		}
		if (T[i] == T[j])  //��ȵ�ʱ��j++
		{
			j++;
		}
		next[i] = j;  //��next���鸳ֵ
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
		while (j > 0 && s[i] != t[j])  //���������ֲ���ȵ�Ԫ��
		{
			j = next[j - 1];  //��ʱj���ݵ��ǰ׺��Ӧ��λ��
		}
		if (s[i] == t[j])
		{
			j++;  //��Ϊ����ִ�е����һ��ƥ��Ļ���j��Ȼ��Ҫ��һ������j��λ�þ����ִ������һ��Ԫ�صĺ�һλ����j�Ĵ�С�����Ӵ��ĳ���
		}
		if (j == t.size())  //ƥ��
		{
			return (i - t.size() + 1);  //�����Ӵ�ƥ���λ��
		}
	}
	return -1;

}

int main()
{
	string s, t;
	cout << "������������" << endl;
	cin >> s;
	cout << "������Ҫƥ����ִ���" << endl;
	cin >> t;
	int k = KMP(s,t);
	if (k != -1)
	{
		cout << "��������λ��Ϊ��" << k << endl;
	}
	else
	{
		cout << "��ƥ��" << endl;
	}

	system("pause");

	return 0;
}