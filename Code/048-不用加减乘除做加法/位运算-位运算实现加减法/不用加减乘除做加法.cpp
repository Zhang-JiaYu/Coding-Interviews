#include<iostream>
using namespace std;

int Add(int num1, int num2)
{
	int tmp = 0;
	// ��ֹ�����ǲ��ٲ�����λ
	while (num2 != 0)
	{
		// δ��λ��λ����ɵĶ�����
		tmp = num1 ^ num2;
		// ��λ��λ����ɵĶ����� 
		num2 = (num1 & num2) << 1;
		num1 = tmp;
	}
	return num1;
}

int main() {
	return 0;
}