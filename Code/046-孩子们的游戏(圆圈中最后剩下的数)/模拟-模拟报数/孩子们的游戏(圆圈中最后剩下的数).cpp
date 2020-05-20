#include<iostream>
#include<list>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
	if (n <= 0 || m <= 0)
		return -1;
	// 用链表来表示围城的圈
	list<int> circle;
	for (int i = 0; i < n; i++)
		circle.push_back(i);
	// 遍历链表的指针
	list<int>::iterator p = circle.begin();
	list<int>::iterator tmp = circle.begin();
	// 每次实际需要移动的步数
	int step = 0;
	while (circle.size() > 1)
	{
		step = (m-1) % circle.size();
		// 找到需要移除的节点
		while (step--)
		{
			p++;
			if (p == circle.end())
				p = circle.begin();
		}
		tmp = circle.erase(p);
		// 被删除节点的下一个节点
		p = tmp == circle.end() ? circle.begin() : tmp;
	}
	return *p;
}

int main() {
	return 0;
}