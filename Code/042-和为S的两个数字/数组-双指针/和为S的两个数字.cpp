#include<iostream>
#include<vector>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	vector<int> res;
	int len = array.size();
	if (len < 2)
		return res;
	// ×óÓÒÖ¸Õë
	int l = 0, r = len - 1;
	while (l < r)
	{
		if (array[l] + array[r] == sum)
		{
			res.push_back(array[l]);
			res.push_back(array[r]);
			break;
		}
		if (array[l] + array[r] > sum)
			r--;
		else
			l++;
	}
	return res;
}

int main() {
	return 0;
}

