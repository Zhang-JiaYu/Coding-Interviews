#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pathHelper(vector<vector<int>>& res, vector<int>& node, TreeNode* root, int expectNumber)
{
	if (root == nullptr)
		return;
	if (expectNumber - root->val >= 0)
	{
		node.push_back(root->val);
		if (expectNumber - root->val == 0)
		{
			//�Ӹ��ڵ㵽��Ҷ�ӽڵ����һ��·��
			if (root->left == nullptr && root->right == nullptr)
				res.push_back(node);
		}
		else
		{
			pathHelper(res, node, root->left, expectNumber - root->val);
			pathHelper(res, node, root->right, expectNumber - root->val);
		}
		// ��ԭ·��
		node.pop_back();
	}
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) 
{
	// ����������е�·�����
	vector<vector<int>> res;
	if (root == nullptr)
		return res;
	// ����·��
	vector<int> node;
	pathHelper(res, node, root, expectNumber);
	return res;
}

int main() {
	return 0;
}