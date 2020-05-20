#include<iostream>
#include<vector>
using namespace std;

bool judgeSquenceOfBST(vector<int> sequence, int left, int right)
{
	if (left > right)
		return true;
	int p = right - 1;
	// �ҵ����ڵ�����ӣ����������ڵ��������
	while (p >= left && sequence[p] > sequence[right])
		p--;
	// �ж��������ϵĽڵ��Ƿ��С�ڸ��ڵ�
	for (int i = p; i >= left; i--)
	{
		if (sequence[i] > sequence[right])
			return false;
	}
	// �ж����������������Ƿ�Ϊ�Ϸ��ĺ�������
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