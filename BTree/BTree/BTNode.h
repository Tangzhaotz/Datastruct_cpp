#pragma once
#ifndef BTNode

class BTNode
{
public:

	BTNode();
	~BTNode();
	void PreTraverseBTree();  //前序遍历二叉树
	void InTraverseBTree();  //中序遍历二叉树
	void PostTraverseBTree();  //后序遍历二叉树
	friend void CreateBTree(BTNode* T);
private:
	char data;  //数据域
	BTNode* plchild;  //左孩子
	BTNode* prchild;  //右孩子

};

#endif // !BTNode

