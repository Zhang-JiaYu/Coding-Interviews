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
	// 模拟滑动窗口，保存元素下标
	deque<int> q;
	for (int i = 0; i < len; i++)
	{
		// 删除比新元素小的元素，其已经不可能是窗口中的最大值
		if (!q.empty())
		{
			for (int j = q.size() - 1; j >= 0; j--)
			{
				if (num[q[j]] <= num[i])
					q.erase(q.begin() + j);
			}
		}
		q.push_back(i);
		// 直到第一个窗口形成
		if (i >= size - 1)
		{
			// 删除不在窗口内的元素
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