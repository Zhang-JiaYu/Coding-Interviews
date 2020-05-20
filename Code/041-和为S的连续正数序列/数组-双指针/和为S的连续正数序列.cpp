#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> FindContinuousSequence(int sum)
{
	vector<vector<int>> res;
	// ָ�򻬶��������˵�����ָ��
	int l = 1, r = 2;
	int num = 0;
	while (l < r)
	{
		// ��˹���
		num = (l + r) * (r - l + 1) / 2;
		if (num == sum)
		{
			vector<int> nums;
			// �������ڵ����ݷ�������
			for (int i = l; i <= r; i++)
				nums.push_back(i);
			res.push_back(nums);
			l++;
		}
		if (num > sum)
			l++;
		else
			r++;
	}
	return res;
}

int main() {
	return 0;
}