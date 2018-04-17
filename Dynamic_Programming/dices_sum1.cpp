#include <iostream>
using namespace std;
#include <vector>

vector<pair<int, double> > dicesSum(int n) {
        // Write your code here
        double **all = new double*[n + 1];
        for (int i = 0; i <= n; i++) {
            all[i] = new double[6 * n + 1];
            for (int j = 1; j < 6 * n + 1; j++) {
                all[i][j] = 0.0;
            }
        }
        
        for (int i = 1; i <= 6; i++) {
            all[1][i] = 1.0 / 6;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 6 * i; j++) {//j <= 6*n+1改为6*i
                for (int k = 1; k <= 6; k++){// k=0改成k=1
		    if (j > k) {//添加了一个判断条件
                    	all[i][j] = all[i-1][j-k] + all[i][j]; }
                }
                all[i][j] = all[i][j] / 6;
            }
        }
        
        vector<pair<int, double> > results;
        
        for (int i = n; i <= 6 * n; i++){
            printf("%lf ", all[n][i]);
            results.push_back(make_pair(i, all[n][i]));
        }
	return results;
    }

int main() {
	int n;
	cin >> n;
	vector<pair<int, double> > temp;
	temp = dicesSum(n);
	return 0;
}
