#include <iostream>
using namespace std;
string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string str1 = "1";
        string str2 = "";
        for (int i = 2; i <= n; i++) {
            int num = 1;
            for(int j = 0; j < str1.size() - 1; j++) {
                if (str1[j] == str1[j+1]){
                    num++;
                }
                else {
                    //printf("num %d\n", num);
                    str2 = str2 + (char)num;
                    str2 = str2 + str1[j];
                    num = 1;
                }
            }
            if (str1[str1.size() - 2] != str1[str1.size() - 1]) {
                str2 = str2 + "1";
                str2 = str2 + str1[str1.size() - 1];
            }
            else {
                str2 = str2 + (char)num;
                str2 = str2 + str1[str1.size() - 1];
            }
            
            str1 = str2;
            printf("size %d\n", str1.size());
            printf("str %s\n", str1);
            if (i < n) {
                str2 = "";
            }
        }
        return str1;
    }

int main(){
	int n;
	cin >> n;
	countAndSay(n);	
	return 0;
}
