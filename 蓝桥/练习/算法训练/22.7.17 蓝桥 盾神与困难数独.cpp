#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > matrix(9, vector<int>(9));//数独矩阵
vector<vector<bool> > rowFlag(9, vector<bool>(10, 0));//行标记
vector<vector<bool> > colFlag(9, vector<bool>(10, 0));//列标记
vector<vector<bool> > groupFlag(9, vector<bool>(10, 0));//小组标记

int dfs(int num) {
	if (num == 81) {//递归边界
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		return 1;
	}
	//计算row,col
	int x = num / 9, y = num % 9,groupIndex;
	//将坐标转换成对应的小组序号
	groupIndex = (x / 3) * 3 + (y / 3);
	//dfs+回溯
	if (matrix[x][y] == 0) {
		for (int i = 1; i <= 9; ++i) {
			if (rowFlag[x][i] == 0 && colFlag[y][i] == 0 && groupFlag[groupIndex][i] == 0) {
				matrix[x][y] = i;
				rowFlag[x][i] = 1;
				colFlag[y][i] = 1;
				groupFlag[groupIndex][i] = 1;
				if (dfs(num + 1))
					return 1;
				groupFlag[groupIndex][i] = 0;
				matrix[x][y] = 0;
				rowFlag[x][i] = 0;
				colFlag[y][i] = 0;
			}
		}
	}
	else {
		if (dfs(num + 1))
			return 1;
	}
	return 0;
}

int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> matrix[i][j];
			if (matrix[i][j] != 0) {
				int groupIndex = (i / 3) * 3 + (j / 3);
				//如果在输入的时候发现已经不满足条件，直接输出NO并结束
				if (rowFlag[i][matrix[i][j]] || colFlag[j][matrix[i][j]] || groupFlag[groupIndex][matrix[i][j]] ) {
					cout << "NO";
					return 0;
				}
				rowFlag[i][matrix[i][j]] = 1;
				colFlag[j][matrix[i][j]] = 1;
				groupFlag[groupIndex][matrix[i][j]] = 1;
			}
		}
	}
	if (dfs(0) == 0)cout << "NO";
	//system("pause");
	return 0;
}
