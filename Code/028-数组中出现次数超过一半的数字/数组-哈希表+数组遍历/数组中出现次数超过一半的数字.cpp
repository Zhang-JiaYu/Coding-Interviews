#include<iostream>
#include<vector>
#include<map>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	int len = numbers.size();
	if (len == 0)
		return 0;
	if (len == 1)
		return numbers[0];
	// 记录每个元素出现次数
	map<int, int> count;
	for (int i = 0; i < len; i++)
	{
		count[numbers[i]] += 1;
		if (count[numbers[i]] > len / 2)
			return numbers[i];
	}
	return 0;
}

int main() {
	return 0;
}