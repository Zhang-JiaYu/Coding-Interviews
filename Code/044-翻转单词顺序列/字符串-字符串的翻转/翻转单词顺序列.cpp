#include<iostream>
#include<algorithm>
using namespace std;

// ��ת�ַ�����left��right�Ĳ���
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
	// ��ת�����ַ���
	reverse(str, 0, len-1);
	int l = 0, r = 0;
	// ��תÿ������
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			r = i - 1;
			reverse(str, l, r);
			l = i + 1;
		}
	}
	// ��ת���һ������
	reverse(str, l, len - 1);
	return str;
}

int main() {
	return 0;
}