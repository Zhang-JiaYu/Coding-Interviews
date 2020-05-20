#include<iostream>
#include<algorithm>
using namespace std;

// 翻转字符串从left到right的部分
void reverse(string& str, int left, int right)
{
	while (left < right)
		swap(str[left++], str[right--]);
}

string LeftRotateString(string str, int n) 
{
	int len = str.size();
	if (len <= 1)
		return str;
	// 真正需要移动的次数
	n %= len;
	// YX = (X.T Y.T).T
	reverse(str, 0, n-1);
	reverse(str, n, len - 1);
	reverse(str, 0, len - 1);
	return str;
}

int main() {
	return 0;
}