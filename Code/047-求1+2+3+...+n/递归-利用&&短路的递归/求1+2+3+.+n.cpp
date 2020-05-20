#include<iostream>
using namespace std;

int Sum_Solution(int n) 
{
	int sum = n;
	(n >= 1) && (sum += Sum_Solution(n - 1));
	return sum;
}

int main() {
	return 0;
}