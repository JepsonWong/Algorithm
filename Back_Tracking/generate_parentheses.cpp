/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include <iostream>
#include <vector>
using namespace std;

void generate(int l, int r, string str, vector<string> &all) {
	if (l == r && l == 0) {
		all.push_back(str);
		return;
	}
	if (l > r)
		return;
	if (l > 0) {
		generate(l - 1, r, str + "(", all);
	}
	if (r > 0) {
		generate(l, r - 1, str + ")", all);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	string str("");
	vector<string> all;
	generate(n, n, str, all);
	vector<string>::iterator begin;
	for (begin = all.begin(); begin != all.end(); begin++)
		printf("%s\n", (*begin).c_str());
	return 0;
}
