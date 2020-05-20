#include<iostream>
#include<map>
using namespace std;

string str = "";
// 记录每个字符出现次数
map<char, int> m;

void Insert(char ch)
{
	str += ch;
	m[ch] += 1;
}

char FirstAppearingOnce()
{
	int len = str.size();
	for (int i = 0; i < len; i++)
		if (m[str[i]] == 1)
			return str[i];
	return '#';
}

int main() {
	return 0;
}