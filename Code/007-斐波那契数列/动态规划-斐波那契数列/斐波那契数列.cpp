#include<iostream>
using namespace std;

int Fibonacci(int n) 
{
	if (n <= 1)
		return n;
	int tmp1 = 0, tmp2 = 1;
	while (n-- > 1)
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