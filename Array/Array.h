#pragma once
class Arr
{
public:
	Arr(int len = 50);  //���캯������ʼ������ĳ���
	~Arr();  //��������
	bool append_arr(int val);  //����ĩβ׷��Ԫ��
	bool insert_arr(int pos, int val);  //������posλ�ò���һ��Ԫ��
	bool delete_arr(int pos, int& val);  //ɾ�������е�ĳһ��Ԫ��
	bool is_empty();  //�ж������Ƿ�Ϊ��
	bool is_full(); // �ж������Ƿ�����
	void sort_arr();  //�����С��������
	void show_arr();  //���������Ԫ�صĸ���
	void reverse_arr();//��������
private:
	int* Bbase;  //�洢���������һ��Ԫ�صĵ�ַ
	int len;  //����ĳ���
	int cnt = 0;  //��ǰ������ЧԪ�صĸ����������Ա�ĳ���

};