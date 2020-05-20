#include<iostream>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
	if (pHead1 == nullptr || pHead2 == nullptr)
		return nullptr;
	// ��������ĳ���
	int len1 = 0, len2 = 0;
	ListNode* p1 = pHead1, * p2 = pHead2;
	// �ֱ�õ���������ĳ���
	while (p1 != nullptr)
	{
		len1++;
		p1 = p1->next;
	}
	while (p2 != nullptr)
	{
		len2++;
		p2 = p2->next;
	}
	p1 = pHead1, p2 = pHead2;
	// ��p1ָ��ϳ�������
	if (len1 < len2)
	{
		p1 = pHead2;
		p2 = pHead1;
	}
	// p1��p2��ָ�����
	int steps = abs(len1 - len2);
	while (steps-- > 0)
		p1 = p1->next;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

int main() {
	return 0;
}