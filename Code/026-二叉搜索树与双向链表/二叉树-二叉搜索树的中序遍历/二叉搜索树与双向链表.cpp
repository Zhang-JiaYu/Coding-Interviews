#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// node代表当前遍历节点root在中序遍历过程中的前一个节点
void buildList(TreeNode* root, TreeNode*& front)
{
	if (root == nullptr)
		return;
	buildList(root->left, front);
	// 链表的构建过程
	root->left = front;
	if (front != nullptr)
		front->right = root;
	front = root;
	buildList(root->right, front);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == nullptr)
		return nullptr;
	TreeNode* front = nullptr;
	buildList(pRootOfTree, front);
	// 找到链表的头结点
	TreeNode* p = pRootOfTree;
	while (p->left != nullptr)
		p = p->left;
	return p;
}

int main() {
	return 0;
}