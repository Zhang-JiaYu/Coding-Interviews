#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ·Ç×ÖµäĞòµÄÈ«ÅÅÁĞ
void helper(vector<string>& res, string str, int len, int index)
{
	if (index == len)
		res.push_back(str);
	else
	{
		for (int i = index; i < len; i++)
		{
			if (i != index && str[index] == str[i])
				continue;
			swap(str[index], str[i]);
			helper(res, str, len, index + 1);
			swap(str[index], str[i]);
		}
	}
}

vector<string> Permutation(string str) 
{
	vector<string> res;
	int len = str.size();
	if (len == 0)
		return res;
	helper(res, str, len, 0);
	// °´ÕÕ×ÖµäĞòÅÅĞò
	sort(res.begin(), res.end());
	return res;
}

int main() {
	return 0;
}