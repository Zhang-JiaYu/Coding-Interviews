#include<iostream>
#include<map>
using namespace std;

string str = "";
// ��¼ÿ���ַ����ִ���
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