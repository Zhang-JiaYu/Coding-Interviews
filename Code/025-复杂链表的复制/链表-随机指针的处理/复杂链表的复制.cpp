#include<iostream>
using namespace std;

struct RandomListNode 
{
	int label;
	struct RandomListNode* next, * random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	RandomListNode* p = pHead;
	// �ھ������д���������
	while (p != nullptr)
	{
		RandomListNode* node = new RandomListNode(p->label);
		node->next = p->next;
		p->next = node;
		p = node->next;
	}
	// ��ʼ������������ָ��
	p = pHead;
	while (p != nullptr)
	{
		p->next->random = p->random == nullptr ? nullptr : p->random->next;
		p = p->next->next;
	}
	// �����¾�����
	RandomListNode* head = new RandomListNode(0);
	RandomListNode* clone = head;
	p = pHead;
	while (p != nullptr)
	{
		clone->next = p->next;
		clone = clone->next;
		p->next = clone->next;
		p = p->next;
	}
	return head->next;
}

int main() {
	return 0;
}