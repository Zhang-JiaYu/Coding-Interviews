#include<iostream>
#include<vector>
using namespace std;

// 快排中的获取中轴点位置函数
int getPartition(vector<int>& nums, int left, int right)
{
	int tmp = nums[left];
	while (left < right)
	{
		while (left < right && nums[right] >= tmp)
			right--;
		if (left < right)
			nums[left] = nums[right];
		while (left < right && nums[left] < tmp)
			left++;
		if (left < right)
			nums[right] = nums[left];
	}
	nums[left] = tmp;
	return left;
}

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	int len = numbers.size();
	if (len == 0)
		return 0;
	if (len == 1)
		return numbers[0];
	// 中点下标
	int k = len / 2;
	int left = 0, right = len - 1;
	int index = getPartition(numbers, left, right);
	// 找到数组调整到以中点为轴分割左右数据
	while (index != k)
	{
		if (index > k)
			right = index - 1;
		if (index < k)
			left = index + 1;
		index = getPartition(numbers, left, right);
	}
	// 检查结果是否正确，因为有可能不包含超过一半数量的数字
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (numbers[i] == numbers[index])
			count++;
		if (count > len / 2)
			break;
	}
	return count > len / 2 ? numbers[index] : 0;
}

int main() {
	return 0;
}