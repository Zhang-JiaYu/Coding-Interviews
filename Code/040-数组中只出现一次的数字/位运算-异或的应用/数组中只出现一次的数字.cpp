#include<iostream>
#include<vector>
using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) 
{
	int len = data.size();
	if (len < 2)
		return;
	int tmp = 0;
	// 等于在将数组中两个只出现一次的数进行异或
	for (int i = 0; i < len; i++)
		tmp ^= data[i];
	// 两个数字中不同的最低位
	int bit = 0;
	while (!((tmp >> bit) & 1))
		bit++;
	int n1 = 0, n2 = 0;
	// 为原数组分组
	for (int i = 0; i < len; i++)
	{
		if ((data[i] >> bit) & 1)
			n1 ^= data[i];
		else
			n2 ^= data[i];
	}
	*num1 = n1;
	*num2 = n2;
}

int main() {
	return 0;
}