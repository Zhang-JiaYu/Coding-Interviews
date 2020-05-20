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
	// ÿһ��ڵ���
	int count = 0;
	TreeNode* tmp = nullptr;
	// �жϵ����㻹��˫����
	int flag = 1;
	while (!q.empty())
	{
		count = q.size();
		// ���ڴ��ÿһ��Ľڵ�
		vector<int> nodes;
		while (count--)
		{
			tmp = q.front();
			q.pop();
			// ������������Ҵ洢��ż�����������洢
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