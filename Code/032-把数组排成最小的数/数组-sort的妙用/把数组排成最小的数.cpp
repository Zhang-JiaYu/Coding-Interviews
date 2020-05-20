#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// 按照两个字符串拼接起来的字符串小的顺序来排序 
static bool cmp(int num1, int num2)
{
	// 因为拼接之后可能超过int界限，所以用字符串表达拼接后的数字
	string s1 = to_string(num1) + to_string(num2);
	string s2 = to_string(num2) + to_string(num1);
	return s1 < s2;
}

string PrintMinNumber(vector<int> numbers) 
{
	int len = numbers.size();
	string res = "";
	if (len == 0)
		return res;
	// 排序原数组
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < len; i++)
		res += to_string(numbers[i]);
	return res;
}

int main() {
	return 0;
}