#include<iostream>
using namespace std;

double Power(double base, int exponent) 
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	int tmp = abs(exponent);
	double res = 1;
	while (tmp)
	{
		// 分离出的一次方，最后一定求到幂为1，那时将所有乘积乘到一起，得到最终结果
		if (tmp & 1)
			res *= base;
		base *= base;
		tmp >>= 1;
	}
	return exponent < 0 ? 1 / res : res;
}

int main() {
	return 0;
}