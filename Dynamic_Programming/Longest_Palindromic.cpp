/*
求最长回文子序列的长度。
*/

#include <iostream>
#include <string>
using namespace std;

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
	    else
	    	temp[0][i] = temp[0][i-1];
	}
        for (int i = 0; i < size; i++) {
            if (s[i] == s1[0]) {
	    	temp[i][0] = 1;
	    }
	    else
	    	temp[i][0] = temp[i-1][0];
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
}

int main() {
	string str;
	cin >> str;
	int len = longestPalindrome(str);
	cout << len << endl; 
	return 0;
}
