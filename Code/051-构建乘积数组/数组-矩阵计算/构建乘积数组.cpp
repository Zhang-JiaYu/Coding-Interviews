#include<iostream>
#include<vector>
using namespace std;

vector<int> multiply(const vector<int>& A) 
{
	int len = A.size();
	vector<int> res(len, 1);
	// �������εĳ˻�
	for (int i = len - 2; i >= 0; i--)
		res[i] = res[i + 1] * A[i + 1];
	// �������εĳ˻�
	int tmp = 1;
	for (int i = 1; i < len; i++)
	{
		tmp *= A[i - 1];
		res[i] *= tmp;
	}
	return res;
}

int main() {
	return 0;
}