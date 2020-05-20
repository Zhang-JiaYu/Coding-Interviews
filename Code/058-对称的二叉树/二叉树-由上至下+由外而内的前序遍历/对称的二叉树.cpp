#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool judgeHelper(TreeNode* node1, TreeNode* node2)
{
	if (node1 == nullptr && node2 == nullptr)
		return true;
	if (node1 == nullptr || node2 == nullptr)
		return false;
	if (node1->val != node2->val)
		return false;
	// 从上至下，由外而内进行比较
	return judgeHelper(node1->left, node2->right) && judgeHelper(node1->right, node2->left);
}

bool isSymmetrical(TreeNode* pRoot)
{
	// 空树也属于对称二叉树
	if (pRoot == nullptr)
		return true;
	return judgeHelper(pRoot->left, pRoot->right);
}

int main() {
	return 0;
}