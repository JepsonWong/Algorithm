/*
http://www.cnblogs.com/grandyang/p/5300458.html
树状数组
for (int i = row; i > 0; i = i - (i&(-i))) 谨记i>0
*/

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int> > &matrix) {
		if (matrix.size() <= 0 || matrix[0].size() <= 0)
			return;
		mat.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
		bit.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				update(i, j, matrix[i][j]);
			}
		}
	}
	
	void update(int row, int col, int val) {
		int up = val - mat[row+1][col+1];
		for (int i = row + 1; i < mat.size(); i = i + (i&(-i))) {
			for (int j = col + 1; j < mat.size(); j = j + (j&(-j))) {
				bit[i][j] = bit[i][j] + up;
			}
		}
		mat[row+1][col+1] = val;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return getSum(row2+1,col2+1) - getSum(row2+1,col1) - getSum(row1,col2+1) + getSum(row1, col1);	
	}

	int getSum(int row, int col) {
		int sum = 0;
		for (int i = row; i > 0; i = i - (i&(-i))) {
			for (int j = col; j > 0; j = j - (j&(-j))) {
				sum = sum + bit[i][j];			
			}
		}
		return sum;
	}
	
private:
	vector<vector<int> > mat;
	vector<vector<int> > bit;
};

int main() {
	int array[5][5] = { {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5} };
	vector<vector<int> > a;
	for (int i = 0; i < 5; i++) {
		vector<int> array1(array[i], array[i] + 5);
		a.push_back(array1);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	NumMatrix temp = NumMatrix(a);
	printf("%d\n", temp.sumRegion(2, 1, 4, 3));
	temp.update(3, 2, 2);
	printf("%d\n", temp.sumRegion(2, 1, 4, 3));			
	return 0;
}
