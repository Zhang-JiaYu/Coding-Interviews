#include<iostream>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* ReverseList(ListNode* pHead) 
{
	if (pHead == nullptr)
		return nullptr;
	ListNode* head = new ListNode(0);
	head->next = pHead;
	// 遍历指针
	ListNode* p = pHead;
	ListNode* tmp = nullptr;
	// 头插法
	while (p->next)
	{
		tmp = p->next;
		p->next = tmp->next;
		tmp->next = head->next;
		head->next = tmp;
	}
	return head->next;
}

int main() {
	return 0;
}