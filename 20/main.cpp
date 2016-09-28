#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if (head == NULL || n == 0)
			return head;
		ListNode* p1 = head;
		ListNode* p2 = head;
		ListNode* pt = NULL;
		for(int i = 0; i < n; i++) {
			p1 = p1->next;
		}   
		while (p1!=NULL) {
			pt = p2;
			p1 = p1->next;
			p2 = p2->next;
		}
		if(pt == NULL) {
			return head->next;
		}
		pt->next = p2->next;
		return head;
    }
};

void test(){
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	Solution a = Solution();
	ListNode* res = a.removeNthFromEnd(head, 2);
	while (res!=NULL) {
		cout<<res->val<<endl;
		res = res->next;
	}
}

int main(){
	test();
	return 0;
}
