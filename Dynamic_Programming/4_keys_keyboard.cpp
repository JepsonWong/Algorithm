// 四键的键盘

/*
Imagine you have a special keyboard with the following keys:

Key 1: (A): Print one 'A' on screen.

Key 2: (Ctrl-A): Select the whole screen.

Key 3: (Ctrl-C): Copy selection to buffer.

Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.

Example 1:

Input: N = 3
Output: 3
Explanation: 
We can at most get 3 A's on screen by pressing following key sequence:
A, A, A

Example 2:

Input: N = 7
Output: 9
Explanation: 
We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int *temp = new int[n + 1];
	for (int i = 1; i <= n; i++){
		temp[i] = i;
		for (int j = 2; j < i - 2 ; j++) {
			temp[i] = temp[i] > temp[j] * (i - j - 1) ? temp[i] : temp[j] * (i - j - 1);
		}		
	}
	printf("%d\n", temp[n]);	
	return 0;
}
