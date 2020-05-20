#include<iostream>
#include<map>
using namespace std;

int FirstNotRepeatingChar(string str) 
{
	int len = str.size();
	if (len == 0)
		return -1;
	// 记录每个字符出现的次数
	map<char, int> count;
	for (int i = 0; i < len; i++)
		count[str[i]] += 1;
	for (int i = 0; i < len; i++)
		if (count[str[i]] == 1)
			return i;
	return -1;
}

int main() {
	return 0;
}