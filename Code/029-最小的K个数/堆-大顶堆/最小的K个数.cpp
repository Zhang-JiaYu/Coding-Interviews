#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	int len = input.size();
	vector<int> res;
	if (len < k || k == 0)
		return res;
	//�󶥶� 
	priority_queue<int, vector<int>, less<int>> heap;
	for (int i = 0; i < len; i++)
	{
		if (heap.size() < k)
			heap.push(input[i]);
		else
		{
			if (heap.top() > input[i])
			{
				heap.pop();
				heap.push(input[i]);
			}
		}
	}
	// �����е����ݴ���������
	while (heap.size() > 0)
	{
		res.push_back(heap.top());
		heap.pop();
	}
	return res;
}

int main() {
	return 0;
}