#include<iostream>
#include<string.h>
using namespace std;

// �ж�С���Ƿ���ȷ
bool judgeDecimal(char* str, int left, int right)
{
	// С�����λ��
	int index = -1;
	for (int i = left; i <= right; i++)
	{
		if (i == left && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] == '.')
		{
			// С���㲻������ĩβ���Ҳ��ܳ�������
			if (i == right || index > 0)
				return false;
			index = i;
			continue;
		}
		if (str[i] < '0' || str[i]>'9')
			return false;
	}
	return true;
}

// �ж������Ƿ���ȷ
bool judgeInteger(char* str, int left, int right)
{
	for (int i = left; i <= right; i++)
	{
		if (i == left && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] < '0' || str[i]>'9')
			return false;
	}
	return true;
}

bool isNumeric(char* string)
{
	int len = strlen(string);
	if (len == 0)
		return 0;
	// �ҵ�'e'����'E'��λ��
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		if (string[i] == 'e' || string[i] == 'E')
		{
			index = i;
			break;
		}
	}
	// 'e'�����ڿ�ͷ�ͽ�β
	if (index == 0 || index == len - 1)
		return false;
	// ������'e'�����
	if (index < 0)
		return judgeDecimal(string, 0, len - 1);
	else
		// 'e'�������������
		return judgeDecimal(string, 0, index - 1) && judgeInteger(string, index + 1, len - 1);
}

int main() {
	return 0;
}