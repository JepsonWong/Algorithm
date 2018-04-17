/*
岛屿的数量之二
为了解决这种陆地之间会合并的情况，最好能够将每个陆地都标记出其属于哪个岛屿，这样就会方便我们统计岛屿个数，于是我们需要一个长度为m*n的一维数组来标记各个位置属于哪个岛屿，我们假设每个位置都是一个单独岛屿，岛屿编号可以用其坐标位置表示，但是我们初始化时将其都赋为-1，这样方便我们知道哪些位置尚未开发。
https://blog.csdn.net/qq508618087/article/details/50985158
http://www.cnblogs.com/grandyang/p/5190419.html
*/

#include <iostream>
#include <vector>
using namespace std;

int find(vector<vector<int> >& temp, int m, int i, int j) {
	int i1 = i, j1 = j;
	while (temp[i][j] != m * i + j) {
		i = temp[i][j] / m;
		j = temp[i][j] % m;
	}
	
	while (i1 != i || j1 != j) {
		temp[i1][j1] = temp[i][j];
		i1 = temp[i1][j1] / m;
		j1 = temp[i1][j1] % m;
	}
	
	return temp[i][j];
}

void print(vector<vector<int> > temp) {
	int m = temp.size();
	if (m == 0)
		return;
	int n = temp[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

int main() {
	int m, n;
	cin >> m;
	cin >> n;
	if (m <= 0 || n <= 0)
		return 0;
	int number = 0;
	vector<vector<int> > temp(m, vector<int>(n, -1));
	
	vector<pair<int, int> > positions;
	positions.push_back(make_pair(0, 0));
	//positions.push_back(make_pair(0, 2));
	positions.push_back(make_pair(0, 1));
	//positions.push_back(make_pair(1, 1));
	//positions.push_back(make_pair(2, 0));
	positions.push_back(make_pair(2, 2));
	positions.push_back(make_pair(2, 1));
	
	vector<pair<int, int> > dirs;
	dirs.push_back(make_pair(0, 1));
	dirs.push_back(make_pair(1, 0));
	dirs.push_back(make_pair(0, -1));
	dirs.push_back(make_pair(-1, 0)); 

	int size = positions.size();
	int size1 = dirs.size();
	for (int i = 0; i < size; i++) {
		int x = positions[i].first;
		int y = positions[i].second;
		number++;
		temp[x][y] = m * x + y;
		for (int j = 0; j < size1; j++) {
			int x1 = dirs[j].first;
			int y1 = dirs[j].second;
			int x2 = x1 + x;
			int y2 = y1 + y;
			if (/*temp[x2][y2] == -1 || */x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || temp[x2][y2] == -1) {
				continue;
			}
			int new_id = find(temp, m, x2, y2);
			if (temp[x][y] != new_id) {
				temp[x2][y2] = temp[x][y];
				number--;
			}
		}
		cout << number << endl;		
		print(temp);
	}

	return 0;
}
