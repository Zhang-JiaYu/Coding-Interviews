#include<iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) 
{
	if (length < 2)
		return false;
	for (int i = 0; i < length; i++)
	{
		int index = numbers[i] >= length ? numbers[i] - length : numbers[i];
		if (numbers[index] >= length)
		{
			*duplication = index;
			return true;
		}
		// ��ʾ�Ѿ�index�Ѿ�������һ��
		numbers[index] += length;
	}
	return false;
}

int main() {
	return 0;
}