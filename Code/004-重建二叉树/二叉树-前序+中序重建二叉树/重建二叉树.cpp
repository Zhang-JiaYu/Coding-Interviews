#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 用于保存中序序列中元素的下标
map<int, int> Index;

// index代表树中各个根节点在前序序列的下标
// left和right代表根节点的子树在中序序列中的左右范围，便于得到左子树的节点数
TreeNode* buildTree(vector<int> pre, int index, int left, int right)
{
	if (left > right)
		return nullptr;
	TreeNode* root = new TreeNode(pre[index]);
	// 根节点在中序序列中的下标
	int r_index = Index[pre[index]];
	// 左子树中的节点数
	int len = r_index - left;
	root->left = buildTree(pre, index + 1, left, r_index - 1);
	root->right = buildTree(pre, index + len + 1, r_index + 1, right);
	return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
{
	int len1 = pre.size(), len2 = vin.size();
	if (len1 == 0 || len2 == 0 || len1 != len2)
		return nullptr;
	// 保存中序序列中元素的下标
	for (int i = 0; i < len2; i++)
		Index[vin[i]] = i;
	return buildTree(pre, 0, 0, len1 - 1);
}

int main() {
	return 0;
}