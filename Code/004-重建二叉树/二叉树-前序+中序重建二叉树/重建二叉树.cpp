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

// ���ڱ�������������Ԫ�ص��±�
map<int, int> Index;

// index�������и������ڵ���ǰ�����е��±�
// left��right������ڵ�����������������е����ҷ�Χ�����ڵõ��������Ľڵ���
TreeNode* buildTree(vector<int> pre, int index, int left, int right)
{
	if (left > right)
		return nullptr;
	TreeNode* root = new TreeNode(pre[index]);
	// ���ڵ������������е��±�
	int r_index = Index[pre[index]];
	// �������еĽڵ���
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
	// ��������������Ԫ�ص��±�
	for (int i = 0; i < len2; i++)
		Index[vin[i]] = i;
	return buildTree(pre, 0, 0, len1 - 1);
}

int main() {
	return 0;
}