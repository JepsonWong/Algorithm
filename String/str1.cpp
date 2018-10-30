#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	if (str[0] == '\0')
		return 0;

	int sum = str[0] - 'a';

	for (int i = 1; i < str.size(); i++) {
		sum = sum * pow(26, 1) + (str[i] - 'a');
	}
	
	cout << sum << endl;

	return 0;
}
