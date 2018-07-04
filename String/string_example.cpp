#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
后缀树应用：寻找重复出现过的最长子串
*/

vector<string> suffix_tree(string s) { //构造后缀数组
	vector<string> vs;
	for (int i = 0; i < s.length(); i++) {
		vs.push_back(s.substr(s.length()-i-1, i+1));
	}
	sort(vs.begin(),vs.end());
	return vs;
}

string max_long_commonn_string(vector<string> strs) { //寻找最长公共前缀
	string result;
	int maxlen = 0;
	for (int i = 0; i < strs.size() - 1; i++) {
		string cur = strs[i];
		string suf = strs[i+1];
		int templen = 0;
		cout << "循环开始: " << min(cur.length(), suf.length()) << endl;
		// 需要考虑到如果一个字符串完全和另一个字符串的前缀匹配，例如ab和abcd的前缀匹配，这样导致了虽然更新了templen，但是result却没有更新。因为ab和abcd判断的话，只会一直if判断，if判断玩就出循环了。
		/*for (int j = 0; j < min(cur.length(), suf.length()); j++) {
			cout << "循环: " <<  j << endl;
			if (cur[j] == suf[j]) {
				templen++;
			}	
			else {
				if (templen > maxlen) {
					maxlen = templen;
					result = suf.substr(0, templen);
				}
				cout << cur << " " << templen << endl;
				//templen = 0;
				break;
			}
		}*/
		for (int j = 0; j < min(cur.length(), suf.length()); j++) {
			if (suf[j] == suf[j]) {
				templen++;
				if (templen > maxlen) {
					maxlen = templen;
					result = suf.substr(0, maxlen);
				}
			}
			else {
				break;
			}
		}	
	}
	return result;
}

int main() {
	string str;
	cin >> str;
	
	vector<string> strs = suffix_tree(str);
	cout << "strs output: " << endl;
	for (int i = 0; i < strs.size(); i++) {
		cout << strs[i] << endl;
	}
	string result = max_long_commonn_string(strs);
	
	cout << result << endl;
	return 0;
}
