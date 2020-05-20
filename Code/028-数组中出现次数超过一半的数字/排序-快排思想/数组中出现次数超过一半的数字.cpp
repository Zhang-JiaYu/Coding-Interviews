#include<iostream>
#include<vector>
using namespace std;

// �����еĻ�ȡ�����λ�ú���
int getPartition(vector<int>& nums, int left, int right)
{
	int tmp = nums[left];
	while (left < right)
	{
		while (left < right && nums[right] >= tmp)
			right--;
		if (left < right)
			nums[left] = nums[right];
		while (left < right && nums[left] < tmp)
			left++;
		if (left < right)
			nums[right] = nums[left];
	}
	nums[left] = tmp;
	return left;
}

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	int len = numbers.size();
	if (len == 0)
		return 0;
	if (len == 1)
		return numbers[0];
	// �е��±�
	int k = len / 2;
	int left = 0, right = len - 1;
	int index = getPartition(numbers, left, right);
	// �ҵ�������������е�Ϊ��ָ���������
	while (index != k)
	{
		if (index > k)
			right = index - 1;
		if (index < k)
			left = index + 1;
		index = getPartition(numbers, left, right);
	}
	// ������Ƿ���ȷ����Ϊ�п��ܲ���������һ������������
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (numbers[i] == numbers[index])
			count++;
		if (count > len / 2)
			break;
	}
	return count > len / 2 ? numbers[index] : 0;
}

int main() {
	return 0;
}