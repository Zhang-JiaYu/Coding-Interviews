#include<iostream>
#include<stack>
using namespace std;

// 主栈
stack<int> S;
// 保存最小元素的辅助栈
stack<int> Min;

void push(int value) 
{
	S.push(value);
	if (Min.empty() || Min.top() >= value)
		Min.push(value);
}

void pop() 
{
	if (S.top() == Min.top())
		Min.pop();
	S.pop();
}

int top() 
{
	return S.top();
}

int min() 
{
	return Min.top();
}

int main() {
	return 0;
}