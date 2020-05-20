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
	queue < TreeNode*> q;
	q.push(pRoot);
	// 每一层节点数
	int count = 0;
	TreeNode* tmp = nullptr;
	// 判断单数层还是双数层
	int flag = 1;
	while (!q.empty())
	{
		count = q.size();
		// 用于存放每一层的节点
		vector<int> nodes;
		while (count--)
		{
			tmp = q.front();
			q.pop();
			// 单数层从左往右存储，偶数层从右往左存储
			if (flag % 2)
				nodes.push_back(tmp->val);
			else
				nodes.insert(nodes.begin(), tmp->val);
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
		}
		flag++;
		res.push_back(nodes);
	}
	return res;
}

int main() {
	return 0;
}