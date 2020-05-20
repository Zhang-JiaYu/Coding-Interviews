#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsContinuous(vector<int> numbers)
{
	int len = numbers.size();
	if (len == 0)
		return false;
	sort(numbers.begin(), numbers.end());
	// ��С���ĸ���
	int count = 0;
	int i = 0;
	while (numbers[i++] == 0)
		count++;
	for (i = count + 1; i < len; i++)
	{
		// �ж�ǰ���������Ƿ�Ϊ��ȵ����Լ���С���ܷ����ȱ
		if (numbers[i] == numbers[i - 1] || numbers[i] - numbers[i - 1] - 1 > count)
			return false;
		count -= numbers[i] - numbers[i - 1] - 1;
	}
	return true;
}

int main() {
	return 0;
}