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
	// �ж��Ƿ���ڻ�
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
	// Ѱ�һ����
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