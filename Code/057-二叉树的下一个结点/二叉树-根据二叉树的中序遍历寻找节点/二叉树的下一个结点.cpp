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
	// 该节点有右子节点时
	if (pNode->right)
	{
		p = pNode->right;
		// 找到右子树上的最左节点
		while (p->left)
			p = p->left;
		return p;
	}
	else
	{
		// 该节点为根节点
		if (pNode->next == nullptr)
			return nullptr;
		// 当该节点为其父节点的左子节点时
		if (pNode->next->left == pNode)
			return pNode->next;
		// 当该节点为其父节点的右子节点时
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