/*
实现一个函数，将字符串中的每个空格替换成“%20”，例如，输入“We are happy.”，则输出“We%20are%20happy.”。
*/

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void ReplaceBlank(char *str) {
	if (str[0] == '\0')
		return;
	int len = 0;
	int number = 0;
	int i = 0;
	while (str[i] != '\0') {
		len ++;
		if (str[i] == ' ') {
			number++;
		}
		i++;
	}
	int newlen = len + number * 2;
	
	int index = len;
	int newindex = newlen;
	while (index >=0 && newindex > index) {
		if (str[index] == ' ') {
			str[newindex--] = '0';
			str[newindex--] = '2';
			str[newindex--] = '%'; 
		}
		else {
			str[newindex--] = str[index];
		}
		index = index - 1;		
	}
}

int main() {
	char str[100];
	//scanf("%s", str);
	//printf("%s\n", str);
	gets(str);
	puts(str);
	ReplaceBlank(str);
	printf("%s\n", str);		
	return 0;
}
