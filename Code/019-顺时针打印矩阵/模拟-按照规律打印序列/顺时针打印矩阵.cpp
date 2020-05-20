#include<iostream>
#include<vector>
using namespace std;

vector<int> printMatrix(vector<vector<int>> matrix)
{
	vector<int> res;
	int width = matrix.size();
	if (width == 0)
		return res;
	int length = matrix[0].size();
	if (length == 0)
		return res;
	// x,y代表每一圈的起点坐标
	int x = 0, y = 0;
	while (width > 0 && length > 0)
	{
		// 上长
		for (int i = 0; i < length; i++)
			res.push_back(matrix[x][y + i]);
		// 右宽
		for (int i = 1; i < width; i++)
			res.push_back(matrix[x + i][y + length - 1]);
		// 下长
		if(width > 1)
			for (int i = 1; i < length; i++)
				res.push_back(matrix[x + width - 1][y + length - 1 - i]);
		// 左宽
		if (length > 1)
			for (int i = 1; i < width - 1; i++)
				res.push_back(matrix[x + width - 1 - i][y]);
		x += 1;
		y += 1;
		width -= 2;
		length -= 2;
	}
	return res;
}

int main() {
	return 0;
}