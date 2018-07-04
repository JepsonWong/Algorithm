#include <stdio.h>

void display(int *p, int sz)
{
	int i = 0;
	printf("数组为: ");
	for (i = 0; i < sz; i++)
		printf("%d ", p[i]);
	printf("\n");
}

void find_num(int *p, int sz) {
	int num = 0;
	int num1 = 0;
	int num2 = 0;
	if (sz % 2 == 1) { //数组元素个数为奇数
		printf("存在一个单数: ");
		for (int i = 0; i < sz; i++) {
			num1 = num1 ^ p[i];
		}
		printf("%d\n", num1);
	}
	else {
		for (int i = 0; i < sz; i++) {
			num = num ^ p[i];
		}
		if (num == 0) {
			printf("不存在单数。\n");
		}
		else {
			printf("存在两个单数:\n");
			int n = 0; //判断num从后数有几个0才遇到1（即低位几个0），说明在第几位开始这两个单数位置的数字不一样									
			n = num & (-num);
			printf("第%d位开始不一样\n", n);

			int n1 = num & ~(num-1);
			printf("第%d位开始不一样\n", n1);
						
			for (int i = 0; i < sz; i++) {
				if (((p[i] >> n) & 1) == 1) {
					num1 = num1 ^ p[i];
				}
				else {
					num2 = num2 ^ p[i];
				}	
			}
			printf("这两个单数为: %d %d\n", num1, num2);
		}
	}
}

int main() {
	int arr1[] = { 1, 3, 5, 7, 1, 8, 3, 5 };
	int arr2[] = { 1, 3, 5, 7, 1, 3, 5 };
	int arr3[] = { 1, 3, 5, 7, 1, 3, 5, 7 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	display(arr1, sz);
	find_num(arr1, sz);
	sz = sizeof(arr2) / sizeof(arr2[0]);
	display(arr2, sz);
	find_num(arr2, sz);
	sz = sizeof(arr3) / sizeof(arr3[0]);
	display(arr3, sz);	
	find_num(arr3, sz);
	return 0;
}
