#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int GetUglyNumber_Solution(int index) 
{
	// 1到6全为丑数
	if (index <= 6)
		return index;
	vector<int> nums(index);
	nums[0] = 1;
	// 分别指向乘以2,3,5最小的数的下标
	int p2 = 0, p3 = 0, p5 = 0;
	int i = 1;
	while (i != index)
	{
		nums[i] = min(nums[p2] * 2, min(nums[p3] * 3, nums[p5] * 5));
		if (nums[i] == nums[p2] * 2)
			p2++;
		if (nums[i] == nums[p3] * 3)
			p3++;
		if (nums[i] == nums[p5] * 5)
			p5++;
		i++;
	}
	return nums[index - 1];
}

int main() {
	return 0;
}