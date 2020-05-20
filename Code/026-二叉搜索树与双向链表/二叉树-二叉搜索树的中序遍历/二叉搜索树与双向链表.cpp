#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// node����ǰ�����ڵ�root��������������е�ǰһ���ڵ�
void buildList(TreeNode* root, TreeNode*& front)
{
	if (root == nullptr)
		return;
	buildList(root->left, front);
	// ����Ĺ�������
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
	// �ҵ������ͷ���
	TreeNode* p = pRootOfTree;
	while (p->left != nullptr)
		p = p->left;
	return p;
}

int main() {
	return 0;
}