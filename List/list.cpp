#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int value;
	ListNode *next;
};

void print(ListNode *head) {
	while (head != NULL) {
		cout << head->value << endl;
		head = head->next;
	}
}

/*
从尾到头打印链表
*/
void printReverse(ListNode *head) {
	if (head != NULL) {
		printReverse(head->next);
		cout << head->value << endl;
	}
	else {
		return;
	}
}

void printReverse_nonrecursion(ListNode *head) {
	stack<ListNode*> s;
	while (head != NULL) {
		s.push(head);
		head = head -> next;
	}
	ListNode *temp;
	while (!s.empty()) {
		temp = s.top();
		cout << temp->value << endl;
		s.pop();
	}
}

int main() {
	ListNode *pHead = NULL;
	int n = 10;
	
	ListNode *temp1 = new ListNode();
	temp1->value = 0;
	temp1->next = NULL;
	pHead = temp1;

	for (int i = 1; i < n; i++) {
		ListNode *temp = new ListNode();
		temp->value = i;
		temp->next = NULL;
		temp1->next = temp;
		temp1 = temp1->next;
	}
	print(pHead);
	cout << "print reverse:" << endl;
	printReverse(pHead);
	cout << "print reverse non-recursion:" << endl;
	printReverse_nonrecursion(pHead);
	return 0;
}
