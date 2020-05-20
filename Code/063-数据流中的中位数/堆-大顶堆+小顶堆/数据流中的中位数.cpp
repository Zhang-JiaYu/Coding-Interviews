#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//大顶堆，保存较小的那一半数，堆顶是前半部分最大的数 
priority_queue<int, vector<int>, less<int>> l;
//小顶堆，保存较大的那一半数，堆顶是后半部分最小的数 
priority_queue<int, vector<int>, greater<int>> r;

void Insert(int num)
{
	if (l.empty() || num <= l.top())
		l.push(num);
	else
		r.push(num);
	// 调节两个堆中的数据量
	// 保证个数为偶数时，两个堆中数据个数相等；奇数时，大顶堆比小顶堆中的数据量大1
	if (l.size() < r.size())
	{
		l.push(r.top());
		r.pop();
	}
	else
	{
		if (l.size() - r.size() > 1)
		{
			r.push(l.top());
			l.pop();
		}
	}
}

double GetMedian()
{
	int len = l.size() + r.size();
	if (len % 2)
		// 总数为奇数的情况
		return (double)l.top();
	else
		// 总数为偶数的情况
		return (l.top() + r.top()) / 2.0;
}

int main() {
	return 0;
}