/*
用数组来记录前缀和
https://blog.csdn.net/bobo1356/article/details/71105934
*/

#include <iostream>
using namespace std;

/*
N个数，要求从中选择若干个连续的数（注意每个数最多只能选一次）加起来，问能形成的最大的和。
*/
/*
int main() {
	int a[100];
	int sum[100] = {0};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 0)
			sum[i] = a[i];
		else
			sum[i] = sum[i-1] + a[i];
	}

	int max = sum[n];
	int ans = -INT_MAX;
	for (int i = n-1; i >= 0; i--) {
		if (max - sum[i] > ans) {
			ans = max - sum[i];
		}
		if (sum[i] > max)
			max = sum[i];
	}
	
	cout << ans << endl;
	
	return 0;
}*/

/*
N个数围成一圈，要求从中选择若干个连续的数（注意每个数最多只能选一次）加起来，问能形成的最大的和。
也可以前缀树后缀树结合https://www.cnblogs.com/Rivendell/p/4141406.html
*/

int main() {
	int a[100];
	int sum[100] = {0};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}

	int max = sum[n];
	int min = sum[n];
	int ans = -INT_MAX;
	for (int i = n-1; i >= 0; i--) {
		if (max -sum[i] > ans) //不是一个圈的情况
			ans = max - sum[i];
		if (sum[n] + sum[i] - min > ans) //是一个圈的情况 注意每个数字只能选一次
			ans = sum[n] + sum[i] - min;
		if (sum[i] > max)
			max = sum[i];
		if (sum[i] < min)
			min = sum[i];
	}
	cout << ans << endl;
	return 0;
}	
