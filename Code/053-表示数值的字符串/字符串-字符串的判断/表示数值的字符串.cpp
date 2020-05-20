#include<iostream>
#include<string.h>
using namespace std;

// 判断小数是否正确
bool judgeDecimal(char* str, int left, int right)
{
	// 小数点的位置
	int index = -1;
	for (int i = left; i <= right; i++)
	{
		if (i == left && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] == '.')
		{
			// 小数点不能在最末尾，且不能出现两次
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

// 判断整数是否正确
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
	// 找到'e'或者'E'的位置
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		if (string[i] == 'e' || string[i] == 'E')
		{
			index = i;
			break;
		}
	}
	// 'e'不能在开头和结尾
	if (index == 0 || index == len - 1)
		return false;
	// 不存在'e'的情况
	if (index < 0)
		return judgeDecimal(string, 0, len - 1);
	else
		// 'e'后面必须是整数
		return judgeDecimal(string, 0, index - 1) && judgeInteger(string, index + 1, len - 1);
}

int main() {
	return 0;
}