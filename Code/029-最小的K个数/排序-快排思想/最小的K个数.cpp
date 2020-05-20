#include<iostream>
#include<vector>
using namespace std;

// �����еĻ�ȡ�����λ�ú���
int getPartition(vector<int>& input, int left, int right)
{
	int tmp = input[left];
	while (left < right)
	{
		while (left < right && input[right] >= tmp)
			right--;
		if (left < right)
			input[left] = input[right];
		while (left < right && input[left] < tmp)
			left++;
		if (left < right)
			input[right] = input[left];
	}
	input[left] = tmp;
	return left;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	vector<int> res;
	int len = input.size();
	if (len == 0 || k == 0 || k > len)
		return res;
	if (k == len)
		return input;
	// �����ҵ��������λ������������
	int left = 0, right = len - 1;
	int index = getPartition(input, left, right);
	while (index != k - 1)
	{
		// index����k-1����index֮ǰѰ�ҵ�k����
		if (index > k - 1)
			right = index - 1;
		// indexС��k-1����index֮��Ѱ�ҵ�k����
		if (index < k - 1)
			left = index + 1;
		index = getPartition(input, left, right);
	}
	for (int i = 0; i < k; i++)
		res.push_back(input[i]);
	return res;
}

int main() {
	return 0;
}