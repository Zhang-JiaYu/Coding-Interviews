#include<iostream>
#include<vector>
using namespace std;

bool Find(int target, vector<vector<int>> array) 
{
	int width = array.size();
	if (width == 0)
		return false;
	int length = array[0].size();
	if (length == 0)
		return false;
	// 二维数组左下角坐标
	int x = width - 1, y = 0;
	while (x >= 0 && y < length)
	{
		if (array[x][y] == target)
			return true;
		if (array[x][y] > target)
			x--;
		else
			y++;
	}
	return false;
}

int main() {
	return 0;
}