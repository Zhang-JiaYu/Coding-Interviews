#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// ���������ַ���ƴ���������ַ���С��˳�������� 
static bool cmp(int num1, int num2)
{
	// ��Ϊƴ��֮����ܳ���int���ޣ��������ַ������ƴ�Ӻ������
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
	// ����ԭ����
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < len; i++)
		res += to_string(numbers[i]);
	return res;
}

int main() {
	return 0;
}