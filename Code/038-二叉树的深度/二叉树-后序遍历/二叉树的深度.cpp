#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	// 左右子树的长度
	int l_len = TreeDepth(pRoot->left);
	int r_len = TreeDepth(pRoot->right);
	return max(l_len, r_len) + 1;
}

int main() {
	return 0;
}