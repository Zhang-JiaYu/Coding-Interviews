#include<iostream>
using namespace std;

int StrToInt(string str) 
{
	int len = str.size();
	if (len == 0)
		return 0;
	// 正负数的最大值的绝对值不同
	long long maxNum = str[0] == '-' ? 2147483648 : 2147483647;
	int i = str[0] == '-' || str[0] == '+' ? 1 : 0;
	// 最终结果
	int res = 0;
	for (; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		// 判断生成的数字是否会溢出
		if (res > maxNum / 10 || (res == maxNum / 10 && (str[i] - '0') > maxNum % 10))
			return 0;
		res = res * 10 + (str[i] - '0');
	}
	res = str[0] == '-' ? -res : res;
	return res;
}

int main() {
	return 0;
}