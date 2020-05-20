#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//�󶥶ѣ������С����һ�������Ѷ���ǰ�벿�������� 
priority_queue<int, vector<int>, less<int>> l;
//С���ѣ�����ϴ����һ�������Ѷ��Ǻ�벿����С���� 
priority_queue<int, vector<int>, greater<int>> r;

void Insert(int num)
{
	if (l.empty() || num <= l.top())
		l.push(num);
	else
		r.push(num);
	// �����������е�������
	// ��֤����Ϊż��ʱ�������������ݸ�����ȣ�����ʱ���󶥶ѱ�С�����е���������1
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
		// ����Ϊ���������
		return (double)l.top();
	else
		// ����Ϊż�������
		return (l.top() + r.top()) / 2.0;
}

int main() {
	return 0;
}