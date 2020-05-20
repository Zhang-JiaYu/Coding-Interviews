#include<iostream>
using namespace std;

int jumpFloorII(int number) 
{
	if (number <= 1)
		return 1;
	int res = 0;
	// i代表的是跳的级数
	for (int i = 1; i <= number; i++)
		res += jumpFloorII(number - i);
	return res;
}

int main() {
	return 0;
}