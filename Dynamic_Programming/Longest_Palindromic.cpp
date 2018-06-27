/*
求最长回文子序列的长度。
求最长回文子串的长度。
求回文子序列的个数。
求原字符串拆分成回文串的最小切割数。如aab需要切割1次变成aa，b。
https://www.cnblogs.com/grandyang/p/4464476.html
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
//最长回文子序列
int longestPalindrome(string s) {
        int size = s.size();
        if (size <= 0) {
            return 0;
        }
        if (size == 1) {
            return 1;
        }
        
        string s1 = "";
        char s2[2] = "";
        for (int i = size - 1; i >=0; i--) {
            s2[0] = s[i];
            s2[1] = '\0';
            s1 = s1 + s2;
        }

	cout << s << endl;
	cout << s1 << endl;
        
        int **temp = new int*[size];
        
        for (int i = 0; i < size ; i++) {
            temp[i] = new int[size];
        }
        
	for (int i = 0; i < size; i++) {
            //temp[0][i] = 0; 之前这里和下方的初始化弄错了，没有判断都初始化成了0 
	   if (s[0] == s1[i]) {
		temp[0][i] = 1;
	    }
	    else if (i == 0) temp[0][i] = 0;
	    else temp[0][i] = temp[0][i-1];
	}
        for (int i = 0; i < size; i++) {
            if (s[i] == s1[0]) {
	    	temp[i][0] = 1;
	    }
	    else if (i == 0) temp[0][i] = 0;
	    else temp[i][0] = temp[i-1][0];
	}
        for (int i = 1; i < size; i++) {
            for (int j = 1; j < size; j++) {
                if (s[i] == s1[j]) {
                    temp[i][j] = temp[i-1][j-1] + 1;
                }
                else {
                    temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
		    //temp[i][j] = max(temp[i][j], temp[i-1][j-1]); // 之前没有判断这一行
                }
            }
        }
        
        return temp[size-1][size-1];
}*/

//最长回文子序列
int longestPalindrome(string s) {
	int n = s.length();
	vector<vector<int> > dp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	for (int j = 0; j < n; j++) {
		dp[j][j] = 1;
		for (int i = j - 1; i >= 0; i--) {
			if (s[i] == s[j])
				dp[i][j] = dp[i+1][j-1] + 2;
			else
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
		}
	}
	return dp[0][n-1];
}

//回文子序列的个数
int numOfPalindrome(string s) {
	int len = s.size();
	cout << s.size() << " " << s.length() << " " << endl;
	vector<vector<int> > dp(len, vector<int>(len));
	for (int j = 0; j < len; j ++) {
		dp[j][j] = 1;
		for (int i = j - 1; i >= 0; i--) {
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			if (s[i] == s[j]) {
				dp[i][j] = 1 + dp[i][j] + dp[i+1][j-1]; //1是头尾组成的回文子序列，后面是去掉头尾的字符串的回文子序列个数
			}	
		}
	}
	return dp[0][len-1];
}

//判断字符串是否为回文
bool isPalindrome(string s) {
	int start = 0;
	int end = s.length() - 1;
	while (start < end) {
		if (s[start] != s[end])
			return false;
		start++;
		end--;
	}
	return true;
}

//最长回文子串
/*
int longestPalindromeSubstring(string s) {
	int n = s.length();
	int longest = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {//注意：j从i+1开始
			if (isPalindrome(s.substr(i, j-i+1)) && ((j-i+1) > longest))
				longest = j - i + 1;
		}
	}
	return longest;	
}*/
/*
//左右搜索判断是否为最长回文子串
void searchPalindrome(string s, int left, int right, int &start, int &n) {
	int step = 1;
	while (left - step >= 0 && right + step < s.size()) {
		if (s[left - step] != s[right + step]) {
			break;
		}
		step++;
	}
	if (right - left + 1 + 2 * step - 2 > n) {
		n = right - left + 1 + 2 * step - 2;
		start = left - step + 1;
	}
}

int longestPalindromeSubstring(string s) {
	int n = s.length();
	int start = 0;
	int len = 0;
	int left = 0, right = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i+1]) {//是否为abba形式
			left = i;
			right = i + 1;
			searchPalindrome(s, left, right, start, len);
		}
		left = right = i;
		searchPalindrome(s, left, right, start, len);
	}
	return len;
}*/
//马拉车算法 复杂度为O(n)
int longestPalindromeSubstring(string s) {
	string t = "$#";
	for (int i = 0; i < s.size(); i++) {
		t = t + s[i];
		t = t + "#";
	}
	int mx = 0, id = 0;
	int resLen = 0, resCenter = 0;//寻找子串的resCenter和resLen
	int k = t.size();
	//int p[k] = {0};
	int *p = new int[k];
	for (int i = 0 ; i < t.size(); i++) {
		p[i] = mx > i ? min(p[2*id - i], mx - i) : 1;
		while (t[i+p[i]] == t[i-p[i]])
			p[i] = p[i] + 1;
		if (mx < i + p[i]) { //更新mx的条件
			id = i;
			mx = i + p[i];
		}
		if (resLen < p[i]) { //更新resLen的条件
			resLen = p[i];
			resCenter = i;
		}
	}
	int start = (resCenter - resLen) / 2;
	resLen = resLen - 1;
	return resLen;
}

//原字符串拆分成回文串的最小切割数
int minCut(string s) {
	int len = s.size();
	bool p[len][len]; //p[i][j]表示string s的i到j之间是否是回文
	int dp[len+1];//记录从当前位置到字符串末尾的切割数
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++)
			p[i][j] = false;
	}
	for (int i = 0; i <= len; i++)
		dp[i] = len - i - 1;
	for (int i = len-1; i >= 0; i--) {
		for (int j = i; j < len; j++) {
			if (s[i] == s[j] && (j - i <= 1 || p[i+1][j-1] == true)) {
//				cout << "begin: "<< i << j << endl;
//				cout << "dp[i]: " << dp[i] << " dp[j+1]+1: " << dp[j+1] + 1 << endl;
				p[i][j] = true;
				dp[i] = min(dp[i], dp[j+1] + 1);	
	}
		}
	}
	return dp[0];
}

int main() {
	string str;
	cin >> str;
	string str_reverse = str;
	reverse(str_reverse.begin(), str_reverse.end());
	cout << "str: " << str  << endl;
	cout << "str reverse: " << str_reverse << endl;
	int is = isPalindrome(str);
	cout << "是否是回文：" << is << endl;
	int len = longestPalindrome(str);
	cout << "最长回文子序列：" << len << endl;
	int sum = numOfPalindrome(str);
	cout << "回文子序列的个数：" << sum << endl;
	int len1 = longestPalindromeSubstring(str);
	cout << "最长回文子串：" << len1 << endl;
	int cut = minCut(str);
	cout << "原字符串拆分成回文串的最小切割数：" << cut << endl;
	return 0;
}
