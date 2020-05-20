#include<iostream>
#include<stack>
using namespace std;

stack<int> stack1;
stack<int> stack2;

void push(int node) 
{
	stack1.push(node);
}

int pop() 
{
	if (stack2.empty())
	{
		// 将stack1中的数据放入stack2中形成数据的逆置
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	int res = stack2.top();
	stack2.pop();
	return res;
}

int main() {
	return 0;
}