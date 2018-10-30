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

/*
反转单链表-递归
*/
ListNode* ReverseList1(ListNode *head, ListNode **result) {
	//if (head == NULL || head->next == NULL) {
	//	return head;
	//}
	// 下面result的更新很有必要，是反转之后的头节点
	if (head == NULL) {
		*result = NULL;
		return head;
	}
	if (head->next == NULL) {
		*result = head;
		return head;		
	}
	ListNode *arr = ReverseList1(head->next, result);
	arr->next = head;
	head->next = NULL;
	return head; //return arr; 返回head，因为要返回链表最末尾，从而让它指向链表最后一个元素
}

/*
反转单链表-非递归
*/
ListNode* ReverseList2(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode* p = head;
	ListNode* q = head->next;
	ListNode* temp;
	head->next = NULL; //此句很重要
	while (q != NULL) {
		temp = q->next;
		q->next = p;
		p = q;
		q = temp;
	}
	return p;
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

	cout << "reverse_list1" << endl;
	ListNode* pHead1 = NULL;
	ReverseList1(pHead, &pHead1);
	print(pHead1);
	cout << "reverse_list2" << endl;
	//ListNode* pHead2 = ReverseList2(pHead);
	//print(pHead2);
	
	return 0;
}
