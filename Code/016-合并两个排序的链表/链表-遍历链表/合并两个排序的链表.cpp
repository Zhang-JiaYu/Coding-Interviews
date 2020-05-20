#include<iostream>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr || pHead2 == nullptr)
		return pHead1 == nullptr ? pHead2 : pHead1;
	ListNode* head = new ListNode(0);
	// p1,p2分别用来遍历两条原始链表，p用来遍历新链表
	ListNode* p1 = pHead1, * p2 = pHead2, * p = head;
	while (p1 != nullptr && p2 != nullptr)
	{
		if (p1->val <= p2->val)
		{
			p->next = p1;
			p1 = p1->next;
		}
		else
		{
			p->next = p2;
			p2 = p2->next;
		}
		p = p->next;
	}
	// 将剩余链表放入新链表
	if (p1 != nullptr)
		p->next = p1;
	if (p2 != nullptr)
		p->next = p2;
	return head->next;
}

int main() {
	return 0;
}