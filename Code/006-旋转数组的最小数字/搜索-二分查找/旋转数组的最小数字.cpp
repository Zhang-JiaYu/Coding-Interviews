#include<iostream>
#include<vector>
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) 
{
	int len = rotateArray.size();
	if (len == 0)
		return 0;
	// 二分查找的左右端点
	int l = 0, r = len - 1;
	int m = 0;
	while (l < r)
	{
		m = l + (r - l) / 2;
		if (rotateArray[m] > rotateArray[len - 1])
			l = m + 1;
		else
			r = m;
	}
	return rotateArray[l];
}

int main() {
	return 0;
}
