/*
求出一个集合的所有子集
*/

#include <iostream>
#include <vector>
using namespace std;

void cset(int index, int i, int n, vector<int> array, vector<int> flag) {
	cout << index << i << endl;
	if (i == 0) {
		cout << "sub_array: ";
		for (int j = 0; j < n; j++) {
			if (flag[j] == 1)
				cout << array[j] << " ";
		}
		cout << endl;
	}
	else {
		//if (index >= n) {
		//	return;
		//}
		for (int j = index; j < n-i+1; j++) {//不是j<n，而是j<n-i+1;要必须写j<n，前面的return注释要去掉
			flag[j] = 1;
			cset(j+1, i-1, n, array, flag);//第一个参数为j+1，而不是index+1
			flag[j] = 0;
		}
	}
}

// 递归求法
void sub_array1(vector<int> array, int n, vector<int> flag) {
	for (int i = 0; i <= n; i++) {
		cout << "含" << i << "个元素的子集." << endl;
		cset(0, i, n, array, flag); //从0开始到末尾，取i个元素
	}	
}

void print_subarray(int mask, vector<int> array, int n) {
	cout << "subarray: ";
	if (mask == 0)
		cout << endl;
	else {
		for (int i = 0; i < n; i++) {
			if (((mask >> i) & 1) == 1) {
				cout << array[i] << " ";
			}
		}
		cout << endl;
	}
}

// 非递归求法
void sub_array2(vector<int> array, int n) {
	if (n > 31)
		cout << "集合原属太多，无法采用此方法。" << endl;
	int min = 0;
	int max = (1 << n) - 1;
	for (int i = min; i <= max; i++) {
		print_subarray(i, array, n);
	}
}

int main() {
	int n;
	vector<int> array;
	cin >> n;
	vector<int> flag(n); //用于标记某一个位置的元素是否被选中
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		array.push_back(temp);
	}
	//sub_array1(array, n, flag);
	sub_array2(array, n);
	return 0;
}
