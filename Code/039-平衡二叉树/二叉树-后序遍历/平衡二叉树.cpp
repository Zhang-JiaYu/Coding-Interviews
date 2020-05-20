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

int getDepth(TreeNode* pRoot, bool& flag)
{
	if (pRoot == nullptr)
		return 0;
	int l_len = getDepth(pRoot->left, flag);
	int r_len = getDepth(pRoot->right, flag);
	// 判断左右子树长度差是否大于1
	if (flag && abs(l_len - r_len) > 1)
		flag = false;
	return max(l_len, r_len) + 1;
}

bool IsBalanced_Solution(TreeNode* pRoot) 
{
	if (pRoot == nullptr)
		return true;
	bool flag = true;
	getDepth(pRoot, flag);
	return flag;
}

int main() {
	return 0;
}