#include<iostream>
#include<vector>
using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) 
{
	int len = data.size();
	if (len < 2)
		return;
	int tmp = 0;
	// �����ڽ�����������ֻ����һ�ε����������
	for (int i = 0; i < len; i++)
		tmp ^= data[i];
	// ���������в�ͬ�����λ
	int bit = 0;
	while (!((tmp >> bit) & 1))
		bit++;
	int n1 = 0, n2 = 0;
	// Ϊԭ�������
	for (int i = 0; i < len; i++)
	{
		if ((data[i] >> bit) & 1)
			n1 ^= data[i];
		else
			n2 ^= data[i];
	}
	*num1 = n1;
	*num2 = n2;
}

int main() {
	return 0;
}