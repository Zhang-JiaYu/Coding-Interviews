#include<iostream>
#include<vector>
using namespace std;

bool judgeSquenceOfBST(vector<int> sequence, int left, int right)
{
	if (left > right)
		return true;
	int p = right - 1;
	// 找到根节点的左孩子，即遍历根节点的右子树
	while (p >= left && sequence[p] > sequence[right])
		p--;
	// 判断左子树上的节点是否均小于根节点
	for (int i = p; i >= left; i--)
	{
		if (sequence[i] > sequence[right])
			return false;
	}
	// 判断左子树和右子树是否为合法的后序序列
	return judgeSquenceOfBST(sequence, left, p) && judgeSquenceOfBST(sequence, p + 1, right - 1);
}

bool VerifySquenceOfBST(vector<int> sequence) 
{
	int len = sequence.size();
	if (len == 0)
		return false;
	return judgeSquenceOfBST(sequence, 0, len - 1);
}

int main() {
	return 0;
}