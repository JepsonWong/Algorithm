/*
https://blog.csdn.net/ruangongshi/article/details/47376965 线段树区间更新
懒惰标记入门题
https://blog.csdn.net/zhou_yujia/article/details/51386549
*/

#include <iostream>
using namespace std;

#define maxn 1000

int m[maxn]; // num是m的4倍

struct Node {
	int l;
	int r;
	int sum;
	int tag;
}num[4 * maxn];

void build(int root, int l, int r) {
	num[root].l = l;
	num[root].r = r;
	num[root].tag = -1;
	if (l == r) {
		num[root].sum = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(root * 2, l, mid);
	build(root * 2 + 1, mid + 1, r);
	num[root].sum = num[root * 2].sum + num[root * 2 + 1].sum;
}

void update(int root, int l1, int r1, int val) {
	int l = num[root].l;
	int r = num[root].r;
	int mid = (l + r) / 2;
	if (l == l1 && r == r1) {
		num[root].tag = val;//延时更新
		cout << "延时更新" << endl;
		num[root].sum = (num[root].r - num[root].l + 1) * val;//
		return;
	}
	if (num[root].tag != -1) {
		//延迟更新的也必须要更新了
		num[root * 2].tag = num[root].tag;
		num[root * 2].sum = (num[root * 2].r - num[root * 2].l + 1) * num[root * 2].tag;
		num[root * 2 + 1].tag = num[root].tag;
		num[root * 2 + 1].sum = (num[root * 2 + 1].r - num[root * 2 + 1].l + 1) * num[root * 2 + 1].tag;
		num[root].tag = -1;
	}
	/*
	更新有问题，如果要这两个if更新，参照网址
	https://blog.csdn.net/weizhuwyzc000/article/details/50445710

	if (l1 <= mid)
		update(root * 2, l1, mid, val);
	if (r1 > mid)
		update(root * 2 + 1, mid + 1, r1, val);
	*/
	if (l1 <= mid && r1 > mid) {
		update(root * 2, l1, mid, val);
		update(root * 2 + 1, mid + 1, r1, val);
	}
	if (l1 <= mid && r1 <= mid) {
		update(root * 2, l1, r1, val);
	}
	if (l1 > mid) {
		update(root * 2 + 1, l1, r1, val);
	}
	num[root].sum = num[root * 2].sum + num[root * 2 + 1].sum; //这里肯定不能按上面的区间计算方法(r-l)*tag，因为区间之内数字不一定一样呀，要一样的化，就不能进如这里了，在之前就return了。
}

// 更新左右儿子
void pushDown(int root) {
	num[root * 2].tag = num[root].tag;
	num[root * 2].sum = (num[root * 2].r - num[root * 2].l + 1) * num[root * 2].tag;
	num[root * 2 + 1].tag = num[root].tag;
	num[root * 2 + 1].sum = (num[root * 2 + 1].r - num[root * 2 + 1].l + 1) * num[root * 2 + 1].tag;
	num[root].tag = -1;
}

int query(int root, int l1, int r1) {
	int l = num[root].l;
	int r = num[root].r;
	cout << "root: " << root << " " << num[root].tag << " 查询区间: "  << l1 << " "<< r1 <<" 节点区间: " << l <<" " << r << endl;
	if (l1 <= l && r1 >= r)
		return num[root].sum;
	int result = 0;
	int mid = (l + r) / 2;
	// 之前没有这个if判断导致出错，因为有的节点是懒惰更新。
	// 你要利用儿子节点，一定要保证儿子节点已经更新
	if (num[root].tag != -1) {
		cout << "query 更新!\n" << endl;
		pushDown(root);
	}
	if (l1 <= mid) { //之前这个是小于号，导致出错。
		result += query(root * 2, l1, r1);
	}
	if (r1 > mid)
		result += query(root * 2 + 1, l1,r1);
	return result;	
}

int main() {
	int n;
	cin >> n;
	build(1, 0, n - 1);
	cout << "after update: "<<endl;
	for (int i = 1; i < 50; i++) {
		cout << num[i].sum << " ";
	}
	cout << endl;
	cout << num[1].sum << endl;
	
	update(1, 0, 5, 2);
	cout << "after update: "<<endl;
	for (int i = 1; i < 50; i++) {
		cout << num[i].sum << " ";
	}
	cout << endl;
	cout << query(1, 0, 9) << endl;
	
	update(1, 4, 7, 4);
	cout << "after update: "<<endl;
	for (int i = 1; i < 40; i++) {
		cout << num[i].sum << " ";
	}
	cout << endl;
	
	cout << query(1, 0, 9) << endl;
	cout << query(1, 2, 9) << endl;
	cout << query(1, 2, 2) << endl;
	cout << query(1, 4, 4) << endl;
	cout << query(1, 8, 9) << endl;
}
