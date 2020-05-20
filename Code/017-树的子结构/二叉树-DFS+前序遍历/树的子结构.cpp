#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 判断子结构是否对应
bool judgeSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	// T(A中的子树)可以有B没有的节点，但是B不可以有T没有的节点
	if (pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;
	return judgeSubTree(pRoot1->left, pRoot2->left) && judgeSubTree(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;
	// 在A树中寻找和B树根节点相同的节点
	if (pRoot1->val == pRoot2->val)
	{
		if (judgeSubTree(pRoot1, pRoot2))
			return true;
	}
	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

int main() {
	return 0;
}