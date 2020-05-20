#include<iostream>
using namespace std;

bool match(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*pattern == '\0')
		return false;
	// 处理后面带'*'的字符的情况
	if (*(pattern + 1) != '\0' && *(pattern + 1) == '*')
	{
		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
			return match(str + 1, pattern) || match(str, pattern + 2);
		else
			// 匹配不到直接跳过
			return match(str, pattern + 2);
	}
	else
	{
		// 处理后面不带'*'的字符的情况
		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
			return match(str + 1, pattern + 1);
		else
			return false;
	}
}

int main() {
	return 0;
}