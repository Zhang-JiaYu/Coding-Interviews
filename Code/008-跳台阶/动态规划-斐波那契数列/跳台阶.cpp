#include<iostream>
using namespace std;

int jumpFloor(int number) 
{
	if (number <= 1)
		return number;
	int tmp1 = 1, tmp2 = 1;
	while (number-->1)
	{
		// ��ʹ���м��������쳲�������ʽ
		tmp2 += tmp1;
		tmp1 = tmp2 - tmp1;
	}
	return tmp2;
}

int main() {
	return 0;
}