#include<iostream>
#include<map>
using namespace std;

// ���ڱ���ͨ�������Ѿ��ó���ֵ
map<int, double> value;

double myPow(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	// ���֮ǰ�Ѿ��õ������ֵ����ôֱ�ӷ��ر����ֵ
	if (value.count(exponent) != 0)
		return value[exponent];
	 double res = myPow(base, exponent / 2) * myPow(base, exponent - exponent / 2);
	 value[exponent] = res;
	 return res;
}

double Power(double base, int exponent) 
{
	if (base == 0)
		return 0;
	double res = myPow(base, abs(exponent));
	return exponent < 0 ? 1 / res : res;
}

int main() {
	return 0;
}