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

vector<vector<int>> Print(TreeNode* pRoot) 
{
	vector<vector<int>> res;
	if (pRoot == nullptr)
		return res;
	queue<TreeNode*> q;
	q.push(pRoot);
	// 每一层节点个数
	int len = 0;
	TreeNode* tmp = nullptr;
	// 层次遍历
	while (!q.empty())
	{
		len = q.size();
		vector<int> nodes;
		while(len--)
		{
			tmp = q.front();
			q.pop();
			nodes.push_back(tmp->val);
			if (tmp->left != nullptr)
				q.push(tmp->left);
			if (tmp->right != nullptr)
				q.push(tmp->right);
		}
		res.push_back(nodes);
	}
	return res;
}

int main() {
	return 0;
}