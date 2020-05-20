#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// 用于保存中序序列中元素下标
map<int, int> Index;

// index代表树中各个根节点在后序序列的下标，left和right代表根节点在中序序列中的左右范围
bool judgeSquenceOfBST(vector<int> sequence, int index, int left, int right)
{
	if (left > right)
		return true;
	// 根节点在中序序列中的下标 
	int m_index = Index[sequence[index]];
	if (m_index<left || m_index>right)
		return false;
	// 右子树长度
	int r_len = right - m_index;
	return judgeSquenceOfBST(sequence, index - r_len - 1, left, m_index - 1) &&
		judgeSquenceOfBST(sequence, index - 1, m_index + 1, right);
}

bool VerifySquenceOfBST(vector<int> sequence) 
{
	int len = sequence.size();
	if (len == 0)
		return false;
	// 中序遍历序列 
	vector<int> mid = sequence;
	sort(mid.begin(), mid.end());
	// 记录中序遍历序列中各数字的下标 
	for (int i = 0; i < len; i++)
		Index[mid[i]] = i;
	return judgeSquenceOfBST(sequence, len-1, 0, len-1);
}

int main() {
	return 0;
}