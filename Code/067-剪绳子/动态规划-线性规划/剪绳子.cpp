#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cutRope(int number) 
{
	// res[i]代表长度为i时最大乘积
	vector<int> res(number + 1);
	res[0] = 1;
	res[1] = 1;
	// i代表绳子的长度
	for (int i = 2; i <= number; i++)
	{
		// j代表剪去的长度
		for (int j = 1; j <= i; j++)
		{
			// 除了目标长度其余长度都可以一刀不剪 
			if (j == i && i == number)
				continue;
			res[i] = max(res[i], res[i - j] * j);
		}
	}
	return res[number];
}

int main() {
	return 0;
}