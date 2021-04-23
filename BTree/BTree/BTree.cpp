#include"BTNode.h"
#include"BTree_operation.h"
#include<iostream>
using namespace std;

void CreateBTree(BTNode* T)
{
	char ch;
	cout << "请输入树的元素：" << endl;
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
	cout << "前序:";
	T->PreTraverseBTree();
	cout << endl;

	cout << "中序:";
	T->InTraverseBTree();
	cout << endl;

	cout << "后序:";
	T->PostTraverseBTree();
	cout << endl;

	system("pause");
	return 0;
}