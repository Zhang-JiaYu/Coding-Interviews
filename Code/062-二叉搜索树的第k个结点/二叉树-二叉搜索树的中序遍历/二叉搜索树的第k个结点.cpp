#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(TreeNode* pRoot, int& k)
{
	if (pRoot == nullptr)
		return nullptr;
	TreeNode* res = helper(pRoot->left, k);
	// 如果已经找到了就直接返回节点，不再进行遍历
	if (res)
		return res;
	if (--k == 0)
		return pRoot;
	res = helper(pRoot->right, k);
	return res;
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == nullptr)
		return nullptr;
	return helper(pRoot, k);
}

int main() {
	return 0;
}