#include<iostream>
#include<vector>
using namespace std;

long long countHelper(vector<int>& data, vector<int>& copy, int start, int end)
{
	if (start == end)
		return 0;
	int length = (end - start) / 2;
	long long left = countHelper(copy, data, start, start + length);
	long long right = countHelper(copy, data, start + length + 1, end);
	// 分别指向两个子数组的指针
	int i = start + length;
	int j = end;
	// 指向复制数组的指针
	int index = end;
	long long count = 0;
	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[index--] = data[i--];
			// count = count + j - (start + length + 1) + 1;
			count += j - start - length;
		}
		else
			copy[index--] = data[j--];
	}
	// 将子数组的剩余部分放入复制数组
	for (; i >= start; i--)
		copy[index--] = data[i];
	for (; j >= start + length + 1; j--)
		copy[index--] = data[j];
	return left + right + count;
}

int InversePairs(vector<int> data)
{
	int len = data.size();
	if (len == 0)
		return 0;
	vector<int> copy(len);
	for (int i = 0; i < len; i++)
		copy[i] = data[i];
	return countHelper(data, copy, 0, len - 1) % 1000000007;
}

int main() {
	return 0;
}