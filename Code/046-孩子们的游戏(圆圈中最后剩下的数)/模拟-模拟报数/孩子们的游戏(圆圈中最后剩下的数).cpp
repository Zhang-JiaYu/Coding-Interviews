#include<iostream>
#include<list>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
	if (n <= 0 || m <= 0)
		return -1;
	// ����������ʾΧ�ǵ�Ȧ
	list<int> circle;
	for (int i = 0; i < n; i++)
		circle.push_back(i);
	// ���������ָ��
	list<int>::iterator p = circle.begin();
	list<int>::iterator tmp = circle.begin();
	// ÿ��ʵ����Ҫ�ƶ��Ĳ���
	int step = 0;
	while (circle.size() > 1)
	{
		step = (m-1) % circle.size();
		// �ҵ���Ҫ�Ƴ��Ľڵ�
		while (step--)
		{
			p++;
			if (p == circle.end())
				p = circle.begin();
		}
		tmp = circle.erase(p);
		// ��ɾ���ڵ����һ���ڵ�
		p = tmp == circle.end() ? circle.begin() : tmp;
	}
	return *p;
}

int main() {
	return 0;
}