#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	int len = pushV.size();
	if (len == 0)
		return false;
	// ģ�����ջ���̵�ջ
	stack<int> s;
	// ��ջ���е��±�
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		s.push(pushV[i]);
		while (!s.empty() && s.top() == popV[index])
		{
			s.pop();
			index++;
		}
	}
	return s.empty();
}

int main() {
	return 0;
}