#include<iostream>
#include<vector>
using namespace std;

void reOrderArray(vector<int>& array) 
{
	int len = array.size();
	if (len == 0)
		return;
	// a1保存奇数，a2保存偶数
	vector<int> a1, a2;
	for (int i = 0; i < len; i++)
	{
		if (array[i] & 1)
			a1.push_back(array[i]);
		else
			a2.push_back(array[i]);
	}
	int index = 0;
	// 奇数放在前半部分
	for (int i = 0; i < a1.size(); i++)
		array[index++] = a1[i];
	// 偶数放在后半部分
	for (int i = 0; i < a2.size(); i++)
		array[index++] = a2[i];
}

int main() {
	return 0;
}