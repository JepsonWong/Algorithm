/*
敌兵布阵
http://acm.hdu.edu.cn/showproblem.php?pid=1166
单点更新区间求和
*/

#include <iostream>
using namespace std;

#define maxn 1000

int m[maxn];

struct node {
	int l;
	int r;
	int sum;
}num[4 * maxn];

void build(int root, int l, int r) {
	num[l].l = l;
	num[l].r = r;
	if (l == r) {
		num[root].sum = m[l];
		return;
	}
	int mid = (l + r) / 2;
	build(root * 2, l, mid);
	build(root * 2 + 1, mid + 1, r);
	num[root].sum = num[root * 2].sum + num[root * 2 + 1].sum;
}

void update(int root, int i, int val) {
	int l = num[root].l;
	int r = num[root].r;
	int mid = (l + r) / 2;
	if (l == r && l == i) {
		num[root].sum = val;
		return;
	}
	if (i <= mid) {
		update(root * 2, i, val);
	}
	else {
		update(root * 2 + 1, i, val);
	}
	num[root].sum = num[root * 2].sum + num[root * 2 + 1].sum;
}

int query(int root, int l, int r) {
	int l1 = num[root].l;
	int r1 = num[root].r;
	int mid = (l1 + r1) / 2;
	if (l <= l1 && r >= r1) {
		return num[root].sum;		 
	}
	int sum = 0;
	if (l <= mid)
		sum += query(root * 2, l, r);
	if (r > mid)
		sum += query(root * 2 + 1, l, r);
	return sum;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
	cout << "ok1" << endl;	

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	build(1, 0, n - 1);

	cout << "ok: " << num[1].sum << endl;
	
	cout << query(1, 0, 5) << endl;
	update(1, 0, 4);
	cout << query(1, 0, 5) << endl;
		
	return 0;
}
