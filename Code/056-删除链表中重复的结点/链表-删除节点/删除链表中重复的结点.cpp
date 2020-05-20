#include<iostream>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	ListNode* head = new ListNode(0);
	head->next = pHead;
	// ��������ָ��
	ListNode* p1 = head, * p2 = pHead;
	int num = 0;
	while (p2)
	{
		num = p2->val;
		int count = 0;
		while(p2->next && p2->next->val == num)
			p2 = p2->next;
		// p1��p2֮������ظ�����
		if (p1->next != p2)
			p1->next = p2->next;
		// p1��p2֮�䲻�����ظ�����
		else
			p1 = p2;
		p2 = p1->next;
	}
	return head->next;
}

int main() {
	return 0;
}