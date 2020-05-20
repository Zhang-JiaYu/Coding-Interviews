#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serializeHelper(TreeNode* root)
{
	if (root == nullptr)
		return "#";
	string str = to_string(root->val) + "!";
	str += serializeHelper(root->left);
	str += serializeHelper(root->right);
	return str;
}

char* Serialize(TreeNode* root) 
{
	string str = serializeHelper(root);
	char* res = new char[str.length() + 1];
	strcpy(res, str.c_str());
	return res;
}

// 这里的参数一定要带引用，否则无法按照正确顺序遍历字符串
TreeNode* deserializeHelper(char*& str)
{
	if (*str == '#')
	{
		str++;
		return nullptr;
	}
	int num = 0;
	// 获取节点的值
	while (*str != '!')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	str++;
	TreeNode* node = new TreeNode(num);
	node->left = deserializeHelper(str);
	node->right = deserializeHelper(str);
	return node;
}

TreeNode* Deserialize(char* str) 
{
	return deserializeHelper(str);
}

int main() {
	return 0;
}