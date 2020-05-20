#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// ���ڱ�������������Ԫ���±�
map<int, int> Index;

// index�������и������ڵ��ں������е��±꣬left��right������ڵ������������е����ҷ�Χ
bool judgeSquenceOfBST(vector<int> sequence, int index, int left, int right)
{
	if (left > right)
		return true;
	// ���ڵ������������е��±� 
	int m_index = Index[sequence[index]];
	if (m_index<left || m_index>right)
		return false;
	// ����������
	int r_len = right - m_index;
	return judgeSquenceOfBST(sequence, index - r_len - 1, left, m_index - 1) &&
		judgeSquenceOfBST(sequence, index - 1, m_index + 1, right);
}

bool VerifySquenceOfBST(vector<int> sequence) 
{
	int len = sequence.size();
	if (len == 0)
		return false;
	// ����������� 
	vector<int> mid = sequence;
	sort(mid.begin(), mid.end());
	// ��¼������������и����ֵ��±� 
	for (int i = 0; i < len; i++)
		Index[mid[i]] = i;
	return judgeSquenceOfBST(sequence, len-1, 0, len-1);
}

int main() {
	return 0;
}