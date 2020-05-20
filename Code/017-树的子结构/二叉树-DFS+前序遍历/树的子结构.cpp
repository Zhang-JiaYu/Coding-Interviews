#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// �ж��ӽṹ�Ƿ��Ӧ
bool judgeSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	// T(A�е�����)������Bû�еĽڵ㣬����B��������Tû�еĽڵ�
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
	// ��A����Ѱ�Һ�B�����ڵ���ͬ�Ľڵ�
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