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
		// �������һ�η������һ������Ϊ1����ʱ�����г˻��˵�һ�𣬵õ����ս��
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