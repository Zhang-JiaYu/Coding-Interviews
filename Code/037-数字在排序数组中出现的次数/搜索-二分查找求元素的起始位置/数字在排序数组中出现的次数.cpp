#include<iostream>
#include<vector>
using namespace std;

int GetNumberOfK(vector<int> data, int k) 
{
	int len = data.size();
	if (len == 0)
		return 0;
	int left = 0, right = len - 1, mid = 0;
	// k在数组中的起始位置
	int start = -1, end = -1;
	// 寻找k在数组中的起始位置
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (data[mid] == k)
		{
			start = mid;
			// 继续向前搜索是否还有k
			right = mid - 1;
		}
		if (data[mid] < k)
			left = mid + 1;
		if (data[mid] > k)
			right = mid - 1;
	}
	// 数组中不存在k之和返回0
	if (start < 0)
		return 0;
	// 寻找k在数组中的终止位置
	left = 0, right = len - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (data[mid] == k)
		{
			end = mid;
			// 继续向后搜索是否还有k
			left = mid + 1;
		}
		if (data[mid] < k)
			left = mid + 1;
		if (data[mid] > k)
			right = mid - 1;
	}
	return end - start + 1;
}

int main() {
	return 0;
}