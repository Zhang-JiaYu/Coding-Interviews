#include<iostream>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	if (pListHead == nullptr || k == 0)
		return nullptr;
	// ����ָ��
	ListNode* slow = pListHead, * fast = pListHead;
	while (k--)
	{
		// ���k��������Χ��ֱ�ӷ���nullptr
		if (fast == nullptr)
			return nullptr;
		fast = fast->next;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main() {
	return 0;
}