#include<iostream>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
	if (n <= 0 || m <= 0)
		return -1;
	// ֻ��һ��С���ѵ����������Ϊ0
	int res = 0;
	for (int i = 2; i <= n; i++)
		res = (res + m) % i;
	return res;
}

int main() {
	return 0;
}