#include<iostream>
#include<vector>
using namespace std;

// 快排中的获取中轴点位置函数
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
	// 根据找到的中轴点位置来调整数组
	int left = 0, right = len - 1;
	int index = getPartition(input, left, right);
	while (index != k - 1)
	{
		// index大于k-1则向index之前寻找第k个数
		if (index > k - 1)
			right = index - 1;
		// index小于k-1则向index之后寻找第k个数
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