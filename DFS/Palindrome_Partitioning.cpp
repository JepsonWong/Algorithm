//拆分回文串

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end) {
	while (start < end) {
		if (str[start] != str[end])
			return false;
		start++;
		end--;
	}
	return true;
}

void partitionDFS(string s, int i, vector<string> &out, vector<vector<string> > &res) {
	int n = s.length();
	if (i == n) {
		res.push_back(out);
		return;
	}
	for (int j = i; j < n; j++) {
		if (isPalindrome(s, i, j)) {
			out.push_back(s.substr(i, j-i+1));
			partitionDFS(s, j+1, out, res);
			out.pop_back();//一定要pop出来
		}
	}
}

int main() {
	string str;
	cin >> str;
	
	vector<vector<string> > res;
	vector<string> out;
	int i = 0;
	partitionDFS(str, i, out, res);
	
	int n = res.size();
	for (int i = 0; i < n; i++) {
		int m = res[i].size();
		for (int j = 0; j < m; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
