#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cutRope(int number) 
{
	// res[i]������Ϊiʱ���˻�
	vector<int> res(number + 1);
	res[0] = 1;
	res[1] = 1;
	// i�������ӵĳ���
	for (int i = 2; i <= number; i++)
	{
		// j�����ȥ�ĳ���
		for (int j = 1; j <= i; j++)
		{
			// ����Ŀ�곤�����೤�ȶ�����һ������ 
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