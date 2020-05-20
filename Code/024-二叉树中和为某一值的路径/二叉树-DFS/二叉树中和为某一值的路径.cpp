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
			//从根节点到到叶子节点才是一条路径
			if (root->left == nullptr && root->right == nullptr)
				res.push_back(node);
		}
		else
		{
			pathHelper(res, node, root->left, expectNumber - root->val);
			pathHelper(res, node, root->right, expectNumber - root->val);
		}
		// 还原路径
		node.pop_back();
	}
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) 
{
	// 保存最后所有的路径结果
	vector<vector<int>> res;
	if (root == nullptr)
		return res;
	// 保存路径
	vector<int> node;
	pathHelper(res, node, root, expectNumber);
	return res;
}

int main() {
	return 0;
}