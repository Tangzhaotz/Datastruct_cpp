#include"BTNode.h"
#include"BTree_operation.h"
#include<iostream>
using namespace std;

void CreateBTree(BTNode* T)
{
	char ch;
	cout << "����������Ԫ�أ�" << endl;
	cin >> ch;
	if ('#' == ch)
	{
		T = NULL;
	}
	else
	{
		T->data = ch;
		T->plchild = new BTNode;
		CreateBTree(T->plchild);
		T->prchild = new BTNode;
		CreateBTree(T->prchild);
	}
}

int main()
{
	BTNode* T = new BTNode;
	CreateBTree(T);
	cout << "ǰ��:";
	T->PreTraverseBTree();
	cout << endl;

	cout << "����:";
	T->InTraverseBTree();
	cout << endl;

	cout << "����:";
	T->PostTraverseBTree();
	cout << endl;

	system("pause");
	return 0;
}