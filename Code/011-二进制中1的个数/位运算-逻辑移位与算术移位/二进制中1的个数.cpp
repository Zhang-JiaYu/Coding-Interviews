#include<iostream>
using namespace std;

int  NumberOf1(int n) 
{
	int count = 0;
	for (int i = 0; i < 32; i++)
		if ((n >> i) & 1)
			count++;
	return count;
}

int main() {
	return 0;
}