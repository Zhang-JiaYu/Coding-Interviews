#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) 
{
	int len = array.size();
	if (len == 1)
		return array[0];
	// dp[i] 表示以array[i] 结尾的子数组的最大和
	vector<int> dp(len);
	dp[0] = array[0];
	int res = dp[0];
	for (int i = 1; i < len; i++)
	{
		dp[i] = max(dp[i - 1] + array[i], array[i]);
		res = max(dp[i], res);
	}
	return res;
}

int main() {
	return 0;
}