#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsContinuous(vector<int> numbers)
{
	int len = numbers.size();
	if (len == 0)
		return false;
	sort(numbers.begin(), numbers.end());
	// 大小王的个数
	int count = 0;
	int i = 0;
	while (numbers[i++] == 0)
		count++;
	for (i = count + 1; i < len; i++)
	{
		// 判断前后两张牌是否为相等的牌以及大小王能否填补空缺
		if (numbers[i] == numbers[i - 1] || numbers[i] - numbers[i - 1] - 1 > count)
			return false;
		count -= numbers[i] - numbers[i - 1] - 1;
	}
	return true;
}

int main() {
	return 0;
}