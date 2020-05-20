#include<iostream>
#include<stack>
using namespace std;

// ��ջ
stack<int> S;
// ������СԪ�صĸ���ջ
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