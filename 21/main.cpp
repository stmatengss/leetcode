#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<stack>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        if (l1 == NULL)
        {
        	if (l2 == NULL)return NULL;
        	return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
        if (l1->val > l2->val) {
        	head = new ListNode(l2->val);
        	l2 = l2->next;
		} else {
			head = new ListNode(l1->val);
        	l1 = l1->next;
		}
        ListNode* p = head;
        while (l1 != NULL || l2 !=NULL) {
        	if (l1 == NULL) {
        		p->next = l2;
//        		cout<<" "<<(l2->val)<<endl;
        		break;
			} else if (l2 == NULL) {
        		p->next = l1;
//        		cout<<" "<<(l1->val)<<endl;
        		break;
			} else if (l1->val > l2->val) {
        		p->next = new ListNode(l2->val);
//        		cout<<(l2->val)<<endl;
        		p = p->next;
        		l2 = l2->next;
			} else {
				p->next = new ListNode(l1->val);
//				cout<<(l1->val)<<endl;
				p = p->next;
        		l1 = l1->next;
			}
		}
//		delete p;
		return head;
    }
};

void test(){
	ListNode* head1 = new ListNode(1);
	ListNode* p = head1;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(7);
	p = p->next;
	p->next = new ListNode(9);
	ListNode* head2 = new ListNode(3);
	p = head2;
	p->next = new ListNode(5);
	p = p->next;
	p->next = new ListNode(6);
	p = p->next;
	p->next = new ListNode(8);
	p = p->next;
	p->next = new ListNode(10);
	p = p->next;
	p->next = new ListNode(11);
	p = p->next;
	p->next = new ListNode(12);
	Solution a = Solution();
	ListNode* res = a.mergeTwoLists(head1,head2);
	while (res!=NULL) {
		cout<<res->val<<endl;
		res = res->next;
	}
}

int main(){
	test();
	return 0;
}
