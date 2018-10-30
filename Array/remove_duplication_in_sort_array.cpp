#include <iostream>
#include <vector>
using namespace std;

int remove_duplicates(vector<int>& array) {
	int size = array.size();
	int left = 0;
	int right = 1;
	if (size == 0) {
		return 0;
	}
	if (size == 1) {
		return 1;
	}
	for (int i = right; i < size; i++) {
		if (array[i] != array[i-1]) {
	array[left] = array[i-1];
	left = left + 1;
	}
	}
	array[left] = array[size - 1];
	return left+1;
}

int main() {
	vector<int> array;
	//array.push_back(0);
	//array.push_back(0);
	//array.push_back(1);
	//array.push_back(1);
	//array.push_back(1);
	//array.push_back(2);
	//array.push_back(2);
	//array.push_back(3);
	//array.push_back(3);
	array.push_back(4);
	int return_ = remove_duplicates(array);

	for (int i = 0; i < return_; i++) {
	cout << array[i] << " ";
}
	cout << endl;

	return 0;
}
