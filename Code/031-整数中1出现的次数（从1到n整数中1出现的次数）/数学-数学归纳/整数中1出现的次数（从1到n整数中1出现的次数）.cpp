#include<iostream>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	if (n < 1)
		return 0;
	if (n < 10)
		return 1;
	// 1���ֵĴ���
	int count = 0;
	// i��ʾ��ǰ����������һ��λ
	for (int i = 1; i <= n; i *= 10)
	{
		int high = n / i;
		int low = n % i;
		count += (high + 8) / 10 * i;
		// ��ǰλΪ1�����
		if (high % 10 == 1)
			count += low + 1;
	}
	return count;
}

int main() {
	return 0;
}