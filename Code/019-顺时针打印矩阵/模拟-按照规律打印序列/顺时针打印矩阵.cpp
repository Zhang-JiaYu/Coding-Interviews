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
	// x,y����ÿһȦ���������
	int x = 0, y = 0;
	while (width > 0 && length > 0)
	{
		// �ϳ�
		for (int i = 0; i < length; i++)
			res.push_back(matrix[x][y + i]);
		// �ҿ�
		for (int i = 1; i < width; i++)
			res.push_back(matrix[x + i][y + length - 1]);
		// �³�
		if(width > 1)
			for (int i = 1; i < length; i++)
				res.push_back(matrix[x + width - 1][y + length - 1 - i]);
		// ���
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