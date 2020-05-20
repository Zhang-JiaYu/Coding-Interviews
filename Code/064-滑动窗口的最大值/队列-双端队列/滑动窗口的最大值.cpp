#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	int len = num.size();
	vector<int> res;
	if (len == 0 || size <= 0 || size > len)
		return res;
	// ģ�⻬�����ڣ�����Ԫ���±�
	deque<int> q;
	for (int i = 0; i < len; i++)
	{
		// ɾ������Ԫ��С��Ԫ�أ����Ѿ��������Ǵ����е����ֵ
		if (!q.empty())
		{
			for (int j = q.size() - 1; j >= 0; j--)
			{
				if (num[q[j]] <= num[i])
					q.erase(q.begin() + j);
			}
		}
		q.push_back(i);
		// ֱ����һ�������γ�
		if (i >= size - 1)
		{
			// ɾ�����ڴ����ڵ�Ԫ��
			if (q.front() < i - size + 1)
				q.erase(q.begin());
			res.push_back(num[q.front()]);
		}
	}
	return res;
}

int main() {
	return 0;
}