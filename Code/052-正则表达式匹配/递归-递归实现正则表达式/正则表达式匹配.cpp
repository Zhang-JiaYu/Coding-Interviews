#include<iostream>
using namespace std;

bool match(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*pattern == '\0')
		return false;
	// ��������'*'���ַ������
	if (*(pattern + 1) != '\0' && *(pattern + 1) == '*')
	{
		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
			return match(str + 1, pattern) || match(str, pattern + 2);
		else
			// ƥ�䲻��ֱ������
			return match(str, pattern + 2);
	}
	else
	{
		// ������治��'*'���ַ������
		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
			return match(str + 1, pattern + 1);
		else
			return false;
	}
}

int main() {
	return 0;
}