/*
扔 n 个骰子，向上面的数字之和为 S。给定 Given n，请列出所有可能的 S 值及其相应的概率。
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	double **number = new double*[n + 1];
	for (int i = 1; i < n + 1; i++) {
		number[i] = new double[6 * n + 1]();
	}
		
	for (int i = 1; i <= 6; i++) {
		number[1][i] = 1;
		number[1][i] = number[1][i] / 6;
	}	
	
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= 6 * i; j++) {
			for (int k = 1; k <= 6; k++) {
				if (j - k > 0) {
				number[i][j] = number[i][j] + number[i - 1][j - k];}
			}
			number[i][j] = number[i][j] / 6;
		}
	}
	
	for (int i = n; i <= 6 * n; i++) {
		printf("%d %lf \n", i, number[n][i]);
	}	
	
	return 0;
}
