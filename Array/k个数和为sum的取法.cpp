#include <iostream>
#include <vector>
using namespace std;


//递归求法
void countKeyEqualSum1(vector<int> array, int n, int k, int sum, int &count, vector<int> result) {
	if (k == 0 && sum == 0) {
		count++;
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
		cout << endl;
	}
	else {
		if (k <= 0 || n >= array.size()) {
			return;
		}
		else {
			result.push_back(array[n]);
			countKeyEqualSum1(array, n+1, k-1, sum-array[n], count, result);
			result.pop_back();
			countKeyEqualSum1(array, n+1, k, sum, count, result);			
		}
	}
}

// 动态规划
void countKeyEqualSum1(vector<int> array) {
	int dp[][]; //dp[i][j]表是从前
}

int main() {
	int n, k, sum;
	cin >> n;
	cin >> k;
	cin >> sum;
	vector<int> array;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		array.push_back(temp);
	}
	int count = 0;
	vector<int> result;
	countKeyEqualSum1(array, 0, k, sum, count, result);
	cout << "count: " << count << endl;	
	return 0;
}
