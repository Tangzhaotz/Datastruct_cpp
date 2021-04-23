#pragma once
#ifndef BTree_operation
#include"BTNode.h"
#include<iostream>
using namespace std;

BTNode::BTNode()
{

}

BTNode::~BTNode()
{

}

void BTNode::PreTraverseBTree()
{
	if (data)
	{
		cout << data << " ";
	}
	if (plchild != NULL)
	{
		plchild->PreTraverseBTree();  //µÝ¹éµ÷ÓÃ
	}
	if (prchild != NULL)
	{
		prchild->PreTraverseBTree();
	}
	cout << endl;
}

void BTNode::InTraverseBTree()
{
	if (plchild != NULL)
	{
		plchild->InTraverseBTree();
	}
	if (data)
	{
		cout << data << " ";
	}
	if (prchild != NULL)
	{
		prchild->InTraverseBTree();
	}
	cout << endl;
}

void BTNode::PostTraverseBTree()
{
	if (plchild != NULL)
	{
		plchild->PostTraverseBTree();
	}
	if (prchild != NULL)
	{
		prchild->PostTraverseBTree();
	}
	if (data)
	{
		cout << data << " ";
	}
	cout << endl;
}

#endif // !BTree_operation
