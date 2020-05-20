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
	// 在旧链表中创建新链表
	while (p != nullptr)
	{
		RandomListNode* node = new RandomListNode(p->label);
		node->next = p->next;
		p->next = node;
		p = node->next;
	}
	// 初始化新链表的随机指针
	p = pHead;
	while (p != nullptr)
	{
		p->next->random = p->random == nullptr ? nullptr : p->random->next;
		p = p->next->next;
	}
	// 分离新旧链表
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