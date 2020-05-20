#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> PrintFromTopToBottom(TreeNode* root) 
{
	vector<int> res;
	if (root == nullptr)
		return res;
	// ����˳�������нڵ�
	queue<TreeNode*> node;
	node.push(root);
	TreeNode* tmp = nullptr;
	while (!node.empty())
	{
		tmp = node.front();
		node.pop();
		res.push_back(tmp->val);
		// ����ÿ��������ұ���ڵ�
		if (tmp->left)
			node.push(tmp->left);
		if (tmp->right)
			node.push(tmp->right);
	}
	return res;
}

int main() {
	return 0;
}