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
	// 遍历链表指针
	ListNode* p1 = head, * p2 = pHead;
	int num = 0;
	while (p2)
	{
		num = p2->val;
		int count = 0;
		while(p2->next && p2->next->val == num)
			p2 = p2->next;
		// p1和p2之间存在重复数字
		if (p1->next != p2)
			p1->next = p2->next;
		// p1和p2之间不存在重复数字
		else
			p1 = p2;
		p2 = p1->next;
	}
	return head->next;
}

int main() {
	return 0;
}