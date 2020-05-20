#include<iostream>
#include<vector>
using namespace std;

int GetNumberOfK(vector<int> data, int k) 
{
	int len = data.size();
	if (len == 0)
		return 0;
	int left = 0, right = len - 1, mid = 0;
	// k�������е���ʼλ��
	int start = -1, end = -1;
	// Ѱ��k�������е���ʼλ��
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (data[mid] == k)
		{
			start = mid;
			// ������ǰ�����Ƿ���k
			right = mid - 1;
		}
		if (data[mid] < k)
			left = mid + 1;
		if (data[mid] > k)
			right = mid - 1;
	}
	// �����в�����k֮�ͷ���0
	if (start < 0)
		return 0;
	// Ѱ��k�������е���ֹλ��
	left = 0, right = len - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (data[mid] == k)
		{
			end = mid;
			// ������������Ƿ���k
			left = mid + 1;
		}
		if (data[mid] < k)
			left = mid + 1;
		if (data[mid] > k)
			right = mid - 1;
	}
	return end - start + 1;
}

int main() {
	return 0;
}