#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode* pRoot) 
{
	if (pRoot == nullptr || (pRoot->left == nullptr && pRoot->right == nullptr))
		return;
	// ½»»»×óÓÒ×ÓÊ÷
	TreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

int main() {
	return 0;
}