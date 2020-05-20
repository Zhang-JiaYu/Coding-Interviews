#include<iostream>
using namespace std;

int Add(int num1, int num2)
{
	int tmp = 0;
	// 终止条件是不再产生进位
	while (num2 != 0)
	{
		// 未进位的位所组成的二进制
		tmp = num1 ^ num2;
		// 进位的位所组成的二进制 
		num2 = (num1 & num2) << 1;
		num1 = tmp;
	}
	return num1;
}

int main() {
	return 0;
}