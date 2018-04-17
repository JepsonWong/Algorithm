#include <iostream>
#include <vector>
using namespace std;

void generate(int n, vector<int> s, vector< vector<int> > &all){
	if (s.size() == n) {
		all.push_back(s);
		return;
	}
	
	else {
		vector<int>::iterator ret;
		for (int i = 0; i < n; i++) {
			ret = find(s.begin(), s.end(), i);
			// 同一列不可能
			if(ret == s.end()) {
				// 同一斜线不可能
				int j1 = 0;
				int j2 = -1;
				int flag = 0;
				for (ret = s.begin(); ret != s.end(); ret++) {
					j2 = j2 + 1;
					j1 = *ret;
					int i2 = s.size();
					if ((i2 - j2) == (i - j1) || ((i2 - j2) == (-(i - j1))) || ((i2 - j2) == (j1 - i)) || ((i2 - j2) == (- (j1 - i)))){
						flag = 1;
						break;
					}
				}
				if (flag == 1){
					continue;
				}
				vector<int> s_copy = s;
				s_copy.push_back(i);
				generate(n, s_copy, all);
			}
		}
	}
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> s;
	vector< vector<int> > all;
	generate(n, s, all);
	printf("%d\n", all.size());
	return 0;
}
