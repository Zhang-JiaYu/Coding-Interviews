#include<iostream>
using namespace std;

void replaceSpace(char* str, int length) 
{
	if (length == 0)
		return;
	// �ո������
	int count = 0;
	// ͳ�ƿո������
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	// �Ӻ���ǰ�ƶ��ַ�λ��
	for (int i = length - 1; i >= 0; i--)
	{
		if (count == 0)
			return;
		if (str[i] == ' ')
		{
			count--;
			str[i + count * 2] = '%';
			str[i + count * 2 + 1] = '2';
			str[i + count * 2 + 2] = '0';
		}
		else
			str[i + count * 2] = str[i];
	}
}

int main() {
	return 0;
}