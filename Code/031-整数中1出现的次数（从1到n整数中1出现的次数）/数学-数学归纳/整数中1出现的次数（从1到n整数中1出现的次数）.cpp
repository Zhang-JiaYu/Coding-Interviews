#include<iostream>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	if (n < 1)
		return 0;
	if (n < 10)
		return 1;
	// 1出现的次数
	int count = 0;
	// i表示当前分析的是哪一个位
	for (int i = 1; i <= n; i *= 10)
	{
		int high = n / i;
		int low = n % i;
		count += (high + 8) / 10 * i;
		// 当前位为1的情况
		if (high % 10 == 1)
			count += low + 1;
	}
	return count;
}

int main() {
	return 0;
}