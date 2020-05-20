#include<iostream>
#include<algorithm>
using namespace std;

// 翻转字符串从left到right的部分
void reverse(string& str, int left, int right)
{
	while (left < right)
		swap(str[left++], str[right--]);
}

string ReverseSentence(string str) 
{
	int len = str.size();
	if (len <= 1)
		return str;
	// 翻转整个字符串
	reverse(str, 0, len-1);
	int l = 0, r = 0;
	// 翻转每个单词
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			r = i - 1;
			reverse(str, l, r);
			l = i + 1;
		}
	}
	// 翻转最后一个单词
	reverse(str, l, len - 1);
	return str;
}

int main() {
	return 0;
}