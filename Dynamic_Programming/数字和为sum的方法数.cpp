//https://www.jianshu.com/p/8cf7d6909433
//数字和为sum的方法数
#include <iostream>
#include <vector>
using namespace std;

void traceback(vector<vector<int> > m, vector<int> &x, int *array, int n, int sum)  
{  
    for(int i=n;i>=1;i--)  
    {  
        if(m[i][sum]==m[i-1][sum])
            x[i]=0;
        else  
        {  
            x[i]=1;  
            sum-=array[i-1];
        }
    }
}  

int main() {
	int n;
	int sum;
	cin >> n;
	cin >> sum;
	int *array = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	vector<vector<int> > dp(n+1, vector<int>(sum+1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i][j] = dp[i-1][j];
			if (j - array[i-1] >= 0)
				dp[i][j] = dp[i][j] + dp[i-1][j-array[i-1]];
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}

	vector<int> m(n+1);
	traceback(dp, m, array, n, sum);
	for (int i = 1; i <= n; i++)
		cout << m[i] << " ";
	cout << endl;
	cout << dp[n][sum] << endl;
	return 0;
}
