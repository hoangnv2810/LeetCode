#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	ListNode* ans = new ListNode();
	ListNode* temp = ans;
	int carry = 0, num;
	while (p1 != NULL || p2 != NULL) {
		if (p1 != NULL) {
			num += p1->val;
			p1 = p1->next;
		} 
		if (p2 != NULL) {
			num += p2->val;
			p2 = p2->next;
		}
		num += carry;
		carry = num / 10;
		temp->next = new ListNode(num % 10);
		temp = temp->next;
	}
	if (carry) temp->next = new ListNode(1);
	return ans->next;
}

int main() {
	
}