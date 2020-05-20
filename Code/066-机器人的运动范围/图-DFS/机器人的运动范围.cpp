#include<iostream>
#include<vector>
using namespace std;

// 计算坐标数位之和
int getSum(int X, int Y)
{
	int sum = 0;
	while (X)
	{
		sum += X % 10;
		X /= 10;
	}
	while (Y)
	{
		sum += Y % 10;
		Y /= 10;
	}
	return sum;
}

// flag是记录格子是否有被遍历过，k是目标值，rows，cols是方格行列数，x，y是当前坐标
int countHelper(vector<int>& flag, int k, int rows, int cols, int x, int y)
{
	if (x < 0 || x >= rows || y < 0 || y >= cols || getSum(x, y) > k || flag[x * cols + y] == 1)
		return 0;
	flag[x * cols + y] = 1;
	int count = 1;
	// 向四周搜索
	count += countHelper(flag, k, rows, cols, x - 1, y) + countHelper(flag, k, rows, cols, x + 1, y)
		+ countHelper(flag, k, rows, cols, x, y - 1) + countHelper(flag, k, rows, cols, x, y + 1);
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;
	// 记录格子是否有被遍历过
	vector<int> flag(rows * cols);
	return countHelper(flag, threshold, rows, cols, 0, 0);
}

int main() {
	return 0;
}