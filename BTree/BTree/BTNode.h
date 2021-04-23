#pragma once
#ifndef BTNode

class BTNode
{
public:

	BTNode();
	~BTNode();
	void PreTraverseBTree();  //ǰ�����������
	void InTraverseBTree();  //�������������
	void PostTraverseBTree();  //�������������
	friend void CreateBTree(BTNode* T);
private:
	char data;  //������
	BTNode* plchild;  //����
	BTNode* prchild;  //�Һ���

};

#endif // !BTNode

