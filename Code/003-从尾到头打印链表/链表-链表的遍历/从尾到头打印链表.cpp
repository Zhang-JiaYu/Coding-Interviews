#include<iostream>
#include<vector>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

vector<int> printListFromTailToHead(ListNode* head) 
{
	vector<int> res;
	if (head == nullptr)
		return res;
	ListNode* p = head;
	// 遍历链表并逆向保存节点
	while (p != nullptr)
	{
		res.insert(res.begin(), p->val);
		p = p->next;
	}
	return res;
}

int main() {
	return 0;
}