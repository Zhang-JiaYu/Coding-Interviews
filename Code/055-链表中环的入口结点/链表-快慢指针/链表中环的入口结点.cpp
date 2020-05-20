#include<iostream>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	// 判断是否存在环
	ListNode* slow = pHead, * fast = pHead;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (fast == nullptr || fast->next == nullptr)
		return nullptr;
	// 寻找环入口
	slow = pHead;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

int main() {
	return 0;
}