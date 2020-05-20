#include<iostream>
using namespace std;

struct TreeLinkNode 
{
	int val;
	struct TreeLinkNode* left;
	struct TreeLinkNode* right;
	struct TreeLinkNode* next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;
	TreeLinkNode* p = nullptr;
	// �ýڵ������ӽڵ�ʱ
	if (pNode->right)
	{
		p = pNode->right;
		// �ҵ��������ϵ�����ڵ�
		while (p->left)
			p = p->left;
		return p;
	}
	else
	{
		// �ýڵ�Ϊ���ڵ�
		if (pNode->next == nullptr)
			return nullptr;
		// ���ýڵ�Ϊ�丸�ڵ�����ӽڵ�ʱ
		if (pNode->next->left == pNode)
			return pNode->next;
		// ���ýڵ�Ϊ�丸�ڵ�����ӽڵ�ʱ
		if (pNode->next->right == pNode)
		{
			p = pNode->next;
			while (p->next)
			{
				if (p->next->left == p)
					return p->next;
				p = p->next;
			}
		}
	}
	return nullptr;
}

int main() {
	return 0;
}