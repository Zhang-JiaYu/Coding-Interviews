#include<iostream>
#include<vector>
using namespace std;

// flag�Ǽ�¼�����Ƿ��б���������matrix�Ǿ���rows��cols�Ƿ�����������x��y�ǵ�ǰ���꣬str��Ŀ���ַ���
bool pathHelper(vector<int>& flag, char* matrix, int rows, int cols, int x, int y, char* str)
{
	if (*str == '\0')
		return true;
	if (x < 0 || x >= rows || y < 0 || y >= cols || matrix[x * cols + y] != *str || flag[x * cols + y] == 1)
		return false;
	flag[x * cols + y] = 1;
	// ����������
	bool res = pathHelper(flag, matrix, rows, cols, x - 1, y, str + 1) || pathHelper(flag, matrix, rows, cols, x + 1, y, str + 1)
		|| pathHelper(flag, matrix, rows, cols, x, y - 1, str + 1) || pathHelper(flag, matrix, rows, cols, x, y + 1, str + 1);
	// ��ԭ·��
	flag[x * cols + y] = 0;
	return res;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
		return false;
	// ��¼�ڵ��Ƿ񱻱�����
	vector<int> flag(rows * cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i * cols + j] == str[0])
			{
				if (pathHelper(flag, matrix, rows, cols, i, j, str))
					return true;
			}
		}
	}
	return false;
}

int main() {
	return 0;
}